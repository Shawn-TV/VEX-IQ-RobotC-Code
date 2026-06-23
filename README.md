# VEX-IQ-RobotC-Code

## English

This repository collects VEX IQ RobotC programs I wrote while testing drive control, encoders, sensors, LEDs, and simple competition-style routines.

## What devices this is for

These files are for VEX IQ robots programmed with RobotC for VEX IQ. They are meant for a VEX IQ Brain with VEX IQ smart motors and sensors.

Different files use different parts:

- VEX IQ smart motors
- VEX IQ controller joystick/buttons
- distance sensor
- color/grayscale sensor
- gyro sensor
- touch/bumper sensor
- Touch LED
- shooter/feed/arm style mechanism motors

Always check the `#pragma config(...)` lines at the top of a file before running it. Those lines say which ports the program expects.

## Quick start

1. Open RobotC for VEX IQ.
2. Open one `.c` file.
3. Read the `#pragma config(...)` section at the top.
4. Match the ports in RobotC to your real robot.
5. Compile the program.
6. Download it to the VEX IQ Brain.
7. Test with the robot lifted or in a safe area first.
8. Tune motor speeds, encoder values, sensor thresholds, and wait times.

## Folder guide

- `competition-sweep/` has a longer match-style routine.
- `control/` has driver control and touch-controlled motor code.
- `feedback/` has Touch LED color examples.
- `mechanism/` has shooter/feed mechanism control.
- `motion/` has encoder and motor target movement.
- `navigation/` has gyro, line following, and distance sensor behavior.
- `sensors/` has sensor display and counting examples.
- `misc/` has small templates and task/counter demos.

## Programs

### `competition-sweep/championship-sweep-routine.c`

This is a longer routine using several motors and touch sensors. It starts by driving forward, turns, then repeats a loop that waits for a bumper/touch sensor while running mechanism motors. It also uses a motor target for another mechanism motor.

Use this as a match-style autonomous routine example. Before running it, check the drive motors, mechanism motors, and touch sensor ports.

### `control/touch-start-stop-winch.c`

This program uses a touch sensor on port 7 and a motor on motor port 8. While the touch sensor is pressed, the motor runs at full speed. When the sensor is not pressed, the motor stops.

Use this for a simple winch, lift, or motor test where a button acts like a hold-to-run control.

### `control/joystick-drive-basic.c`

This is a simple driver-control program. It reads controller joystick channels and sends them directly to the left and right drive motors.

Use this to test basic controller driving. If the robot turns or drives backward, check motor reversal and joystick channel direction.

### `control/joystick-drive-button-gear.c`

This program uses controller buttons for fixed movement states. One button turns one way, another button turns the other way, and another button drives both motors using a joystick value.

Use this when you want button-based drive actions instead of only smooth joystick driving.

### `feedback/led-touch-gated-sequence.c`

This program uses Touch LEDs. It waits on a Touch LED value, then sets that Touch LED to red, green, and blue in order.

Use this as a small Touch LED state or color-change example.

### `feedback/led-cascade-sequence.c`

This program uses three Touch LEDs. It repeatedly sets LED1 red, then LED2 yellow, then LED3 green with one-second waits.

Use this to test several Touch LEDs or to make a simple status-light sequence.

### `feedback/led-touch-trigger-lightshow.c`

This program uses two Touch LEDs and one touch sensor. When the touch sensor is pressed, it runs a longer red/green/yellow light sequence. When it is not pressed, both LEDs stay blue.

Use this as a touch-triggered light effect or a standby/active status example.

### `mechanism/dual-shooter-joystick-control.c`

This program controls two shooter motors and one feeder motor from controller buttons. One button runs the two shooter motors, and another button runs the feeder motor.

Use this as a starting point for a VEX IQ shooting or feeding mechanism.

### `motion/encoder-loop-forward.c`

This program uses the standard VEX IQ Clawbot model. It repeatedly resets both drive motor encoders, commands both motors to move 360 degrees, and waits for them to stop.

Use this to test repeated encoder-based forward movement.

### `motion/encoder-repeater-forward.c`

This program is another repeated encoder forward example. It defines the drive motors directly, resets their encoders, sends both motors to 360 degrees, and repeats forever.

Use this when you want a simple encoder target loop without relying on the standard model setup.

### `motion/encoder-step-cycle-forward.c`

This is similar to the encoder repeater, but it also includes a fuller robot configuration with sensors and extra motors listed.

Use this as an encoder movement example inside a more complete robot configuration.

### `motion/eight-shape-pattern.c`

This program sends different encoder targets to the left and right motors. First one side travels farther than the other, then the distances switch.

Use this to create a curved or figure-eight style path using motor encoder targets.

### `motion/step-and-rotate-encoder-profile.c`

This program runs two stages of encoder target movement. In the first stage, one motor moves 3600 degrees while the other moves 1800 degrees. In the second stage, the values switch.

Use this to test turning or curved movement based on different left/right motor distances.

### `motion/progressive-turn-distance-profile.c`

This program first moves both motors a short equal distance, then runs a much larger unequal movement where one motor target is 36000 and the other is 18000.

Use this as a larger turn-distance profile. The numbers are large, so check the robot path and test in a safe space.

### `navigation/gyro-heading-hold.c`

This program reads a gyro value and sends a correction target to a motor. It keeps repeating that correction loop.

Use this as a small gyro correction test. The motor and gyro port must match the robot configuration.

### `navigation/gyro-compass-direction-lock.c`

This program reads the gyro and displays a direction word such as south, west, north, or east depending on the angle range. It also moves a motor to correct angle drift when the gyro is more than about 5 degrees away.

Use this as a gyro direction display and correction experiment.

### `navigation/line-follow-state-machine.c`

This program uses a grayscale sensor and two drive motors. It first drives forward, then follows a line. Before the encoder reaches 3200, it corrects one way; after that encoder point, it switches the correction direction.

Use this for a line follower that changes behavior after traveling a certain distance.

### `navigation/line-follow-threshold-state-switch.c`

This program also uses a grayscale sensor and two drive motors. It follows a threshold of 180, then changes the left/right correction behavior after the left motor encoder reaches 2800.

Use this to test a two-phase line following route.

### `navigation/line-follow-while-threshold.c`

This is a compact line follower. It uses the grayscale threshold 180. When the value is on one side of the threshold, one motor moves and the other stops; when it crosses the threshold, the motors switch.

Use this as the simplest RobotC line-following example in this repository.

### `navigation/obstacle-reverse-on-threshold.c`

This program uses a distance sensor. While the distance is greater than 100, the robot drives forward. When the distance goes below that threshold, it changes motor speeds so the robot turns or reverses away.

Use this as a simple obstacle reaction routine.

### `navigation/obstacle-reverse-on-threshold-long.c`

This is a longer version of the distance-sensor obstacle routine. It reserves several distance sensor names and adds a one-second wait after the turn/reverse action.

Use this if your robot has more distance sensors or if you want a slower, more visible obstacle response.

### `sensors/sensor-multi-read-debug.c`

This program displays several sensor values on the VEX IQ Brain screen: grayscale, distance, gyro degrees, and bumper value.

Use this when wiring or calibrating sensors. It helps check whether the Brain is reading the sensors correctly.

### `sensors/telemetry/color-distance-gyro-bumper-debug.c`

This is another sensor debug display. It reads the same basic sensor group: color/grayscale, distance, gyro, and bumper.

Use it as a telemetry/debug version of the multi-sensor readout.

### `sensors/grayline-counting-by-threshold.c`

This program uses a grayscale sensor and two drive motors. It keeps a counter, drives forward, and increments the counter when the grayscale value crosses the threshold logic.

Use this to count gray/dark line events while the robot moves.

### `misc/blank-template.c`

This is an empty RobotC `task main()` file.

Use it as a clean starting point for a new RobotC program.

### `misc/countdown-and-accel-demo.c`

This program displays two numbers: one counts up from 0, and the other counts down from 100. It updates the display with delays.

Use this as a simple display/counter example.

### `misc/task-micro-demo.c`

This program defines two tasks. One task runs a motor briefly, and the other displays and increments a counter. The main task starts both tasks repeatedly.

Use this to see how RobotC tasks and `startTask(...)` work.

## License

This repository uses the MIT License. See [`LICENSE`](./LICENSE).

## 中文

这个仓库存的是我自己写的一些 VEX IQ RobotC 程序，用来测试底盘控制、编码器、传感器、LED 和简单比赛流程。

## 这些代码给什么设备用

这些文件是给 VEX IQ 机器人和 RobotC for VEX IQ 用的。一般需要 VEX IQ Brain、VEX IQ 智能电机和不同的 VEX IQ 传感器。

不同文件会用到：

- VEX IQ 智能电机
- VEX IQ 手柄摇杆/按钮
- 距离传感器
- 颜色/灰度传感器
- 陀螺仪
- 触碰/bumper 传感器
- Touch LED
- 发射、送料、手臂等机构电机

运行前一定要看文件顶部的 `#pragma config(...)`。这些行决定了程序认为电机和传感器插在哪些端口。

## 快速开始

1. 打开 RobotC for VEX IQ。
2. 打开一个 `.c` 文件。
3. 先看顶部的 `#pragma config(...)`。
4. 把 RobotC 里的端口配置改成和你的真实机器人一致。
5. 先编译程序。
6. 下载到 VEX IQ Brain。
7. 第一次测试时，把机器人架起来，或者放在安全区域。
8. 根据实际情况调电机速度、编码器数值、传感器阈值和等待时间。

## 文件夹说明

- `competition-sweep/`：比较长的比赛风格流程。
- `control/`：手柄控制和触摸控制电机。
- `feedback/`：Touch LED 颜色例子。
- `mechanism/`：发射/送料机构控制。
- `motion/`：编码器和电机目标运动。
- `navigation/`：陀螺仪、循线、距离传感器行为。
- `sensors/`：传感器显示和计数。
- `misc/`：模板、任务和计数器小例子。

## 程序说明

### `competition-sweep/championship-sweep-routine.c`

这是一个比较长的流程，使用多个电机和触碰传感器。程序一开始前进、转向，然后重复一段循环：等待 bumper/触碰传感器，同时运行机构电机。它还会给另一个机构电机发送目标位置。

可以当作比赛风格自动流程参考。运行前要检查驱动电机、机构电机和触碰传感器端口。

### `control/touch-start-stop-winch.c`

这个程序用 7 号端口的触碰传感器控制 8 号电机。按住传感器时电机全速运行，松开后电机停止。

适合绞盘、升降机构，或者任何“按住才运行”的电机测试。

### `control/joystick-drive-basic.c`

这是简单手柄驾驶程序。它读取手柄摇杆通道，并直接把数值给左右驱动电机。

适合测试基础遥控驾驶。如果方向反了，检查电机反向设置和摇杆通道。

### `control/joystick-drive-button-gear.c`

这个程序用手柄按钮控制固定动作。一个按钮往一边转，另一个按钮往另一边转，还有一个按钮用摇杆值带动两个电机。

适合测试按钮式底盘控制。

### `feedback/led-touch-gated-sequence.c`

这个程序使用 Touch LED。它等待 Touch LED 的触摸值，然后按顺序设置红、绿、蓝颜色。

适合做 Touch LED 状态切换的小例子。

### `feedback/led-cascade-sequence.c`

这个程序使用三个 Touch LED。它循环把 LED1 设成红色、LED2 设成黄色、LED3 设成绿色，中间有 1 秒等待。

适合测试多个 Touch LED，或者做简单状态灯。

### `feedback/led-touch-trigger-lightshow.c`

这个程序使用两个 Touch LED 和一个触碰传感器。按下触碰传感器时，会运行一段红、绿、黄灯光序列；没按时两个 LED 保持蓝色。

适合做触摸启动的灯光效果，或者待机/运行状态提示。

### `mechanism/dual-shooter-joystick-control.c`

这个程序用手柄按钮控制两个发射电机和一个送料电机。一个按钮启动两个发射电机，另一个按钮启动送料电机。

适合当作 VEX IQ 发射/送料机构的起点。

### `motion/encoder-loop-forward.c`

这个程序使用标准 VEX IQ Clawbot 配置。它不断重置两个驱动电机编码器，让两个电机都转 360 度，然后等待停止。

适合测试重复的编码器前进。

### `motion/encoder-repeater-forward.c`

这是另一个重复编码器前进例子。它直接定义驱动电机，重置编码器，让两个电机都走 360 度，并无限重复。

适合不依赖标准模型配置时使用。

### `motion/encoder-step-cycle-forward.c`

这个程序和 encoder repeater 类似，但配置里还列了更多传感器和额外电机。

适合在更完整的机器人配置里测试编码器运动。

### `motion/eight-shape-pattern.c`

这个程序给左右电机不同的编码器目标。第一段一侧走得远，第二段换另一侧走得远。

可以用来做弧线或类似 8 字路线的运动测试。

### `motion/step-and-rotate-encoder-profile.c`

这个程序分两段运行编码器目标。第一段一个电机走 3600 度、另一个走 1800 度；第二段两个数值对调。

适合测试左右距离不同造成的转弯或弧线运动。

### `motion/progressive-turn-distance-profile.c`

这个程序先让两个电机走一小段相同距离，然后运行一段很大的不等距运动，一个目标是 36000，另一个是 18000。

适合测试比较大的转向距离。数值很大，运行前要留足空间。

### `navigation/gyro-heading-hold.c`

这个程序读取陀螺仪数值，并把修正目标发送给电机，不断重复。

适合做陀螺仪纠偏的小测试。

### `navigation/gyro-compass-direction-lock.c`

这个程序读取陀螺仪角度，根据角度范围在屏幕上显示 south、west、north、east 等方向。角度偏差超过大约 5 度时，它会让电机做纠偏动作。

适合做陀螺仪方向显示和纠偏实验。

### `navigation/line-follow-state-machine.c`

这个程序用灰度传感器和左右驱动电机循线。它先前进一段，然后循线；编码器到 3200 前按一种方式修正，到 3200 后换另一种方式修正。

适合做“走到某个距离后切换循线策略”的路线。

### `navigation/line-follow-threshold-state-switch.c`

这个程序也用灰度传感器和两个驱动电机。它使用 180 作为阈值循线，并在左电机编码器达到 2800 后切换左右修正方式。

适合测试两阶段循线。

### `navigation/line-follow-while-threshold.c`

这是一个更短的循线程序。它用灰度阈值 180 判断，阈值一边时一侧电机走、另一侧停；跨过阈值后两侧交换。

适合作为这个仓库里最基础的 RobotC 循线例子。

### `navigation/obstacle-reverse-on-threshold.c`

这个程序使用距离传感器。距离大于 100 时机器人前进；距离小于阈值后，它改变两个电机速度，让机器人转开或后退。

适合简单避障反应。

### `navigation/obstacle-reverse-on-threshold-long.c`

这是距离传感器避障的长一点版本。它预留了多个距离传感器名字，并在转向/后退动作后加了 1 秒等待。

如果机器人上有多个距离传感器，或者想让避障动作更明显，可以参考这个。

### `sensors/sensor-multi-read-debug.c`

这个程序在 VEX IQ Brain 屏幕上显示多个传感器数值：灰度、距离、陀螺仪角度和 bumper 值。

适合接线和校准时用来确认传感器有没有读到数据。

### `sensors/telemetry/color-distance-gyro-bumper-debug.c`

这是另一个传感器调试显示程序，读取同样的几类传感器：颜色/灰度、距离、陀螺仪和 bumper。

可以当作 telemetry 版本的多传感器读数显示。

### `sensors/grayline-counting-by-threshold.c`

这个程序使用灰度传感器和两个驱动电机。它会显示一个计数，机器人前进时根据灰度阈值逻辑增加计数。

适合统计机器人经过灰线/深色线的次数。

### `misc/blank-template.c`

这是一个空白的 RobotC `task main()` 文件。

适合当作新程序起点。

### `misc/countdown-and-accel-demo.c`

这个程序在屏幕上显示两个数字：一个从 0 往上数，另一个从 100 往下数，中间有延时。

适合做简单显示和计数练习。

### `misc/task-micro-demo.c`

这个程序定义了两个任务。一个任务短暂运行电机，另一个任务显示并增加计数。主任务会重复启动这两个任务。

适合看 RobotC 的 task 和 `startTask(...)` 怎么用。

## 开源许可

本仓库使用 MIT 协议，详见 [`LICENSE`](./LICENSE)。
