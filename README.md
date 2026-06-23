# vexiq-robotc-code

## English

This repository is a collection of my personal VEX IQ RobotC programs.

It contains practical control demos and competition-style routines for robot modules such as drivetrain, navigation, sensing, mechanism control, and feedback behavior.

### How to use

1. Install RobotC for VEX IQ.
2. Open any `.c` file in RobotC.
3. Configure motors and sensors in the code to match your wiring and ports.
4. Download the file to the VEX IQ brain and run it in the same way you normally test your robot.
5. For each routine, copy one file into a clean RobotC project if needed, then calibrate constants/tuning values before competition use.

### How these files are organized

#### control
- `control/touch-start-stop-winch.c`  
  Touch sensor start/stop control logic for a winch-style mechanism.
- `control/joystick-drive-basic.c`  
  Basic joystick robot movement template.
- `control/joystick-drive-button-gear.c`  
  Button-based gear switching logic for joystick drive.

#### feedback
- `feedback/led-touch-gated-sequence.c`  
  LED light sequence controlled by touch input.
- `feedback/led-cascade-sequence.c`  
  Sequential LED animation routine.
- `feedback/led-touch-trigger-lightshow.c`  
  Event-triggered light show behavior.

#### competition
- `competition-sweep/championship-sweep-routine.c`  
  Competition-oriented sweeping and match-style task routine.

#### mechanism
- `mechanism/dual-shooter-joystick-control.c`  
  Dual-shooter actuator control from joystick input.

#### motion
- `motion/progressive-turn-distance-profile.c`  
  Distance-based progressive turn control.
- `motion/encoder-repeater-forward.c`  
  Repeated forward motion using encoder signals.
- `motion/step-and-rotate-encoder-profile.c`  
  Step-and-rotate profile with encoder feedback.
- `motion/encoder-step-cycle-forward.c`  
  Forward stepping cycle driven by encoder logic.

#### navigation
- `navigation/gyro-heading-hold.c`  
  Gyro-based heading-hold behavior.
- `navigation/gyro-compass-direction-lock.c`  
  Direction lock with compass/heading control.
- `navigation/line-follow-state-machine.c`  
  State-machine style line following.
- `navigation/line-follow-threshold-state-switch.c`  
  Threshold-based state switching for line following.
- `navigation/line-follow-while-threshold.c`  
  Line tracking with threshold detection.
- `navigation/obstacle-reverse-on-threshold.c`  
  Obstacle reaction with reverse action on trigger.
- `navigation/obstacle-reverse-on-threshold-long.c`  
  Long-distance variant of obstacle reverse behavior.

#### sensors
- `sensors/telemetry/color-distance-gyro-bumper-debug.c`  
  Telemetry debug example combining color, distance, gyro, and bumper inputs.
- `sensors/grayline-counting-by-threshold.c`  
  Gray line counting using threshold logic.

#### misc
- `misc/countdown-and-accel-demo.c`  
  Countdown and acceleration demonstration.
- `misc/task-micro-demo.c`  
  Task micro-structure example for RobotC tasks.
- `misc/blank-template.c`  
  Clean template to create new RobotC tasks quickly.

### License

This repository is released under the MIT License. See [`LICENSE`](./LICENSE).

### Author note

All code in this repository is my own and for learning, practice, and competition prototyping.

---

## 中文

本仓库是我个人整理的 VEX IQ RobotC 代码合集，按功能模块分类。

内容覆盖了底盘控制、导航、传感器调试、机构控制、反馈输出以及比赛任务行为等常见场景，可直接用于教学演示、竞赛预演和复盘调参。

### 使用方法

1. 安装 RobotC for VEX IQ 并打开 `.c` 文件。
2. 按实际接线将电机/传感器端口映射到代码中的配置项。
3. 将程序下载到 VEX IQ 机器人主控并运行。
4. 每个任务建议先在空场地测试，再根据实物参数调节阈值、速度和时间常量。

### 文件归类与作用

#### control（控制）
- `control/touch-start-stop-winch.c`  
  用触摸传感器控制卷线/升降机构的启停逻辑。
- `control/joystick-drive-basic.c`  
  基础摇杆底盘控制示例。
- `control/joystick-drive-button-gear.c`  
  摇杆驱动加按键换挡逻辑。

#### feedback（反馈）
- `feedback/led-touch-gated-sequence.c`  
  触摸触发的 LED 序列控制。
- `feedback/led-cascade-sequence.c`  
  阶梯式 LED 灯效。
- `feedback/led-touch-trigger-lightshow.c`  
  触发式灯光秀行为。

#### competition（赛事）
- `competition-sweep/championship-sweep-routine.c`  
  赛场扫描/扫荡任务动作流程。

#### mechanism（机构）
- `mechanism/dual-shooter-joystick-control.c`  
  使用摇杆控制双发射机构。

#### motion（运动）
- `motion/progressive-turn-distance-profile.c`  
  距离驱动的渐进转向控制。
- `motion/encoder-repeater-forward.c`  
  编码器步进正向重复动作。
- `motion/step-and-rotate-encoder-profile.c`  
  编码器反馈的转向+步进流程。
- `motion/encoder-step-cycle-forward.c`  
  编码器步进的前进循环动作。

#### navigation（导航）
- `navigation/gyro-heading-hold.c`  
  陀螺仪航向保持。
- `navigation/gyro-compass-direction-lock.c`  
  陀螺仪/指南针方向锁定。
- `navigation/line-follow-state-machine.c`  
  状态机版本的循线控制。
- `navigation/line-follow-threshold-state-switch.c`  
  阈值切换驱动的循线逻辑。
- `navigation/line-follow-while-threshold.c`  
  阈值循线行为。
- `navigation/obstacle-reverse-on-threshold.c`  
  遇阻阈值后触发倒退策略。
- `navigation/obstacle-reverse-on-threshold-long.c`  
  更长距离版的避障倒退。

#### sensors（传感）
- `sensors/telemetry/color-distance-gyro-bumper-debug.c`  
  色彩/距离/陀螺仪/碰撞传感器联合调试输出示例。
- `sensors/grayline-counting-by-threshold.c`  
  灰线计数与阈值触发示例。

#### misc（其他）
- `misc/countdown-and-accel-demo.c`  
  倒计时与加速示例。
- `misc/task-micro-demo.c`  
  RobotC 任务(Task)的微观流程示例。
- `misc/blank-template.c`  
  空白模板，适合快速搭新项目。

### 开源许可

仓库使用 MIT 协议，详见 [`LICENSE`](./LICENSE)。

### 作者说明

仓库中的代码均为本人编写，供学习、课程实践和机器人比赛原型开发。
