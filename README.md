# VEX IQ RobotC Behavior Routines

## English

This repository contains VEX IQ RobotC programs organized by robot behavior. The examples cover driver control, encoder movement, line following, gyro correction, distance sensing, LED feedback, mechanisms, and match-style routines.

Short description: VEX IQ RobotC behavior routines for drive control, encoders, line following, sensors, LEDs, mechanisms, and match-style sequences.

## What is included

- `competition-sweep/` contains a longer autonomous routine built from drive, mechanism, and sensor steps.
- `control/` contains driver-control and touch-triggered control examples.
- `feedback/` contains Touch LED color sequences and lightshow examples.
- `mechanism/` contains subsystem control such as shooter/feed motors.
- `motion/` contains encoder and motor-target movement patterns.
- `navigation/` contains line following, gyro, and obstacle-response routines.
- `sensors/` contains sensor display and counting/debug examples.
- `misc/` contains small RobotC templates and task/counter demos.

## How to use these files

1. Install and open RobotC for VEX IQ.
2. Open one `.c` file at a time.
3. Before compiling, read the `#pragma config(...)` lines at the top of the file. They define which sensors and motors the program expects.
4. In RobotC, open the Motors and Sensors setup and match the file's ports to your physical robot.
5. If your left/right motor directions are reversed, update the motor configuration or reverse the signs in the motor-speed commands.
6. Click compile first. Fix any port mismatch or missing device before downloading.
7. Download to the VEX IQ Brain.
8. For moving programs, test with the robot lifted or on a safe field before running at full speed.
9. Tune thresholds, encoder targets, gyro values, and speeds for your own robot.

## Beginner notes

- These examples are small routines, not one single full robot project.
- RobotC programs depend heavily on the top-of-file configuration. A program can be logically correct but still fail on a robot with different ports.
- Encoder targets such as `360`, `1800`, or `3200` are starting points. Adjust them after measuring your chassis.
- Line-following thresholds such as `180` depend on the floor, line color, and lighting.
- Motor speeds are written in the RobotC/VEX IQ style, usually from `-100` to `100`.

## Program catalog

### competition-sweep

- `competition-sweep/championship-sweep-routine.c`
  - A longer autonomous sweep routine that combines forward driving, turning, mechanism motors, and a bumper gate. It is useful for studying how a match-style routine is assembled.

### control

- `control/touch-start-stop-winch.c`
  - Runs a motor while a touch sensor is pressed and stops it when released. Useful for winch, lift, or simple safety-gated control.
- `control/joystick-drive-basic.c`
  - Maps joystick channels directly to left and right drive motors.
- `control/joystick-drive-button-gear.c`
  - Uses controller buttons for fixed turn/drive states and includes a joystick fallback mode.

### feedback

- `feedback/led-cascade-sequence.c`
  - Runs a repeated Touch LED cascade using red, yellow, and green status colors.
- `feedback/led-touch-gated-sequence.c`
  - Changes Touch LED colors after touch-based waiting points.
- `feedback/led-touch-trigger-lightshow.c`
  - Starts a two-LED lightshow when a touch sensor is pressed; otherwise it stays in a blue standby state.

### mechanism

- `mechanism/dual-shooter-joystick-control.c`
  - Uses controller buttons to run two shooter motors and one feeder motor.

### motion

- `motion/encoder-loop-forward.c`
  - Repeats a basic encoder-target forward movement forever.
- `motion/encoder-repeater-forward.c`
  - A configured encoder-repeat example with explicit motor names and repeated forward targets.
- `motion/encoder-step-cycle-forward.c`
  - Repeats a one-step encoder movement using configured VEX IQ motors and sensors.
- `motion/eight-shape-pattern.c`
  - Uses different left/right encoder targets to create an alternating path pattern similar to a figure eight.
- `motion/progressive-turn-distance-profile.c`
  - Combines short and long motor targets with different speeds to create a progressive turning profile.
- `motion/step-and-rotate-encoder-profile.c`
  - Runs two encoder target stages with swapped left/right distances.

### navigation

- `navigation/gyro-heading-hold.c`
  - Uses gyro angle feedback to send a correction target to a motor.
- `navigation/gyro-compass-direction-lock.c`
  - Reads gyro angle ranges, displays compass-like direction text, and corrects motor position when the angle drifts.
- `navigation/line-follow-state-machine.c`
  - Follows a line and changes correction direction after an encoder checkpoint.
- `navigation/line-follow-threshold-state-switch.c`
  - Uses grayscale threshold logic, then switches behavior after the left motor passes 2800 encoder counts.
- `navigation/line-follow-while-threshold.c`
  - A compact while-loop line follower using a single grayscale threshold.
- `navigation/obstacle-reverse-on-threshold.c`
  - Drives forward while distance is safe, then reverses/turns when an obstacle is close.
- `navigation/obstacle-reverse-on-threshold-long.c`
  - A longer obstacle-response version with multiple distance sensor names reserved for different mounting positions.

### sensors

- `sensors/grayline-counting-by-threshold.c`
  - Counts grayscale threshold events while driving and displays the count.
- `sensors/sensor-multi-read-debug.c`
  - Continuously displays grayscale, distance, gyro, and bumper readings for debugging.
- `sensors/telemetry/color-distance-gyro-bumper-debug.c`
  - Similar telemetry display stored in a telemetry subfolder for sensor-debug organization.

### misc

- `misc/blank-template.c`
  - Empty `task main()` starter file.
- `misc/counter-display-demo.c`
  - Displays one counter increasing while another counter decreases.
- `misc/task-micro-demo.c`
  - Demonstrates two small RobotC tasks and `startTask(...)` from `task main()`.

## License

This repository is released under the MIT License. See [`LICENSE`](./LICENSE).

## 中文

这个仓库存放的是 VEX IQ RobotC 程序，按机器人行为分类。示例覆盖手柄控制、编码器运动、循线、陀螺仪纠偏、距离传感、LED 反馈、机构控制和竞赛风格流程。

短描述：VEX IQ RobotC 行为例程，覆盖底盘控制、编码器、循线、传感器、LED、机构和竞赛风格动作链。

## 仓库里有什么

- `competition-sweep/`：较长的自动流程，由底盘、机构和传感器步骤组成。
- `control/`：手柄控制和触摸触发控制示例。
- `feedback/`：Touch LED 颜色序列和灯光效果。
- `mechanism/`：发射、送料等机构子系统控制。
- `motion/`：编码器和电机目标位置运动。
- `navigation/`：循线、陀螺仪和避障反应。
- `sensors/`：传感器显示、计数和调试。
- `misc/`：RobotC 模板、任务和计数器小示例。

## 如何使用这些文件

1. 安装并打开 RobotC for VEX IQ。
2. 一次只打开一个 `.c` 文件。
3. 编译前先看文件顶部的 `#pragma config(...)`。这些行定义程序需要哪些电机和传感器。
4. 在 RobotC 的 Motors and Sensors 设置里，把端口改成和你的真实机器人一致。
5. 如果左右电机方向反了，修改电机配置里的 reversed，或者调整电机速度命令的正负号。
6. 先点击 compile 编译。端口不一致或设备缺失时，先修配置再下载。
7. 下载到 VEX IQ Brain。
8. 会移动的程序第一次测试时，把机器人架空或放在安全场地。
9. 根据你的机器人调节阈值、编码器目标、陀螺仪角度和速度。

## 新手注意

- 这些文件是小例程，不是一个完整大工程。
- RobotC 很依赖文件顶部配置。逻辑正确的程序，如果端口和实物不一致，也会跑不起来。
- `360`、`1800`、`3200` 这类编码器数值只是起点，需要按你的底盘实测调整。
- `180` 这类循线阈值受地面、线条颜色和光线影响。
- VEX IQ RobotC 的电机速度通常用 `-100` 到 `100`。

## 程序目录

### competition-sweep

- `competition-sweep/championship-sweep-routine.c`
  - 较长的自动扫场流程，包含前进、转向、机构电机和触碰传感器等待。适合学习竞赛动作链怎么组织。

### 控制（control）

- `control/touch-start-stop-winch.c`
  - 触摸传感器按下时电机运行，松开时停止。适合绞盘、升降或安全门控控制。
- `control/joystick-drive-basic.c`
  - 将手柄通道直接映射到左右驱动电机。
- `control/joystick-drive-button-gear.c`
  - 用手柄按钮控制固定转向/行驶状态，并保留一个摇杆控制模式。

### 反馈（feedback）

- `feedback/led-cascade-sequence.c`
  - 用红、黄、绿状态色循环显示 Touch LED 级联效果。
- `feedback/led-touch-gated-sequence.c`
  - 通过触摸等待点切换 Touch LED 颜色。
- `feedback/led-touch-trigger-lightshow.c`
  - 触摸传感器按下时启动双 LED 灯光秀，否则保持蓝色待机。

### 机构（mechanism）

- `mechanism/dual-shooter-joystick-control.c`
  - 用手柄按钮控制两个发射电机和一个送料电机。

### 运动（motion）

- `motion/encoder-loop-forward.c`
  - 无限重复的基础编码器目标前进。
- `motion/encoder-repeater-forward.c`
  - 带明确电机命名和重复目标的编码器前进示例。
- `motion/encoder-step-cycle-forward.c`
  - 使用配置好的 VEX IQ 电机和传感器，重复执行一步编码器运动。
- `motion/eight-shape-pattern.c`
  - 用不同左右编码器目标组成类似 8 字的交替路线。
- `motion/progressive-turn-distance-profile.c`
  - 通过短/长目标距离和不同速度组合出递进转向。
- `motion/step-and-rotate-encoder-profile.c`
  - 两段编码器目标运动，左右距离对调。

### 导航（navigation）

- `navigation/gyro-heading-hold.c`
  - 使用陀螺仪角度反馈给电机发送纠偏目标。
- `navigation/gyro-compass-direction-lock.c`
  - 按陀螺仪角度区间显示类似指南针方向，并在角度偏移时纠正电机位置。
- `navigation/line-follow-state-machine.c`
  - 循线并在编码器检查点后切换纠偏方向。
- `navigation/line-follow-threshold-state-switch.c`
  - 使用灰度阈值循线，左电机超过 2800 编码器计数后切换行为。
- `navigation/line-follow-while-threshold.c`
  - 使用单一灰度阈值的紧凑 while 循线程序。
- `navigation/obstacle-reverse-on-threshold.c`
  - 距离安全时前进，障碍物接近时后退/转向。
- `navigation/obstacle-reverse-on-threshold-long.c`
  - 更长的避障版本，保留多个距离传感器名，方便不同安装位置使用。

### 传感器（sensors）

- `sensors/grayline-counting-by-threshold.c`
  - 行驶过程中统计灰度阈值事件，并显示计数。
- `sensors/sensor-multi-read-debug.c`
  - 连续显示灰度、距离、陀螺仪和触碰读数，用于调试。
- `sensors/telemetry/color-distance-gyro-bumper-debug.c`
  - 类似的遥测显示，放在 telemetry 子目录中便于分类。

### 其他（misc）

- `misc/blank-template.c`
  - 空白 `task main()` 起手模板。
- `misc/counter-display-demo.c`
  - 一个计数上升、另一个计数下降的显示示例。
- `misc/task-micro-demo.c`
  - 演示两个小 RobotC 任务，以及如何从 `task main()` 调用 `startTask(...)`。

## 开源许可

本仓库使用 MIT 协议，详见 [`LICENSE`](./LICENSE)。
