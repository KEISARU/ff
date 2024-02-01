import asyncio
import threading
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from rtcbot import Websocket, RTCConnection, CVCamera

class Rtcbot_Adapter(Node):
    def __init__(self):
        super().__init__('rtcbot_adapter')
        #self.publisher_ = self.create_publisher()

        self.declare_parameter('publish_frequency', 100.0)
        self.publish_frequency_ = self.get_parameter('publish_frequency').value

        self.declare_parameter('camera_device', '/dev/video0')
        self.camera_device_ = self.get_parameter('camera_device').value

        self.camera_ = CVCamera(cameranumber=-1)
        print("camera")
        self.rtc_connection_ = RTCConnection()
        print("connection")
        self.rtc_connection_.video.putSubscription(self.camera_)
        print("subscription")

        # @self.rtc_connection_.subscribe
        # def onMessage(m):
        #     movement_cmd = Twist()
        #     movement_cmd.linear.x = 0
        #     if m['keyCode'] == 38:
        #         movement_cmd.linear.x = 0.5
        #     if m['keyCode'] == 40:
        #         movement_cmd.linear.x = 0    
        #     movement_cmd.linear.y = 0
        #     movement_cmd.linear.z = 0
        #     movement_cmd.angular.x = 0
        #     movement_cmd.angular.y = 0
        #     movement_cmd.angular.z = 0
        #     if m['keyCode'] == 37:              
        #         movement_cmd.angular.z = 1
        #     if m['keyCode'] == 39:              
        #         movement_cmd.angular.z = -1
        #     #movement_publisher.publish(movement_cmd)
        #     print ("Publishing")       

    async def connect(self):
        ws = Websocket("http://webrtc.stream.robosharing.ai:80/ws")
        print("ws")
        remoteDescription = await ws.get()
        print(f'remote {remoteDescription}')
        robotDescription = await self.rtc_connection_.getLocalDescription(remoteDescription)
        ws.put_nowait(robotDescription)
        print("Started WebRTC")
        await ws.close()


async def spin(node: Node):
    cancel = node.create_guard_condition(lambda: None)
    def _spin(node: Node,
              future: asyncio.Future,
              event_loop: asyncio.AbstractEventLoop):
        while not future.cancelled():
            rclpy.spin_once(node)
        if not future.cancelled():
            event_loop.call_soon_threadsafe(future.set_result, None)
    event_loop = asyncio.get_event_loop()
    spin_task = event_loop.create_future()
    spin_thread = threading.Thread(target=_spin, args=(node, spin_task, event_loop))
    spin_thread.start()
    try:
        await spin_task
    except asyncio.CancelledError:
        cancel.trigger()
    spin_thread.join()
    node.destroy_guard_condition(cancel)


async def main():
    node = Rtcbot_Adapter()
    print("node created")
    spin_task = asyncio.get_event_loop().create_task(spin(node))
    rtc_task = asyncio.get_event_loop().create_task(node.connect())

    await asyncio.wait([spin_task, rtc_task], return_when=asyncio.FIRST_COMPLETED)

    # cancel tasks
    if spin_task.cancel():
        await spin_task
    if rtc_task.cancel():
        await rtc_task

def run():
    rclpy.init()
    asyncio.get_event_loop().run_until_complete(main())
    asyncio.get_event_loop().close()
    rclpy.shutdown()

if __name__ == '__main__':
    run()