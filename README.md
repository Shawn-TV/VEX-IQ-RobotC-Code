# vexiq-robotc-code

## English

This repository is a collection of code I wrote for VEX IQ RobotC.

It is organized by behavior type so each file is easy to find for learning, refactoring, and reuse.

### How to use

1. Install RobotC for VEX IQ.
2. Open one `.c` file.
3. Match the motors and sensors in the code to your wiring and port map.
4. Upload and test on a VEX IQ brain.
5. Use the file as a baseline and tune speeds, thresholds, and delays before using it in a match.

### Detailed file catalog

#### control
- `control/touch-start-stop-winch.c`  
  Touch sensor at port 7 enables motor on while pressed and stops it when released. It is a start/stop template for winch-like motion, gripper, or lever actuation.
- `control/joystick-drive-basic.c`  
  Basic tank-drive mapping with `ChA` and `ChD`, no extra deadband. It is suitable for validating direct joystick to motor response.
- `control/joystick-drive-button-gear.c`  
  Button-control movement demo: two buttons turn left/right, one button drives forward, otherwise motors stop. It is a compact manual control mode with discrete behaviors.

#### feedback
- `feedback/led-touch-gated-sequence.c`  
  Waits on LED-touch state and then changes LED color in three gated steps (`red`, `green`, `blue`). Good for event-gated visual-state demos.
- `feedback/led-cascade-sequence.c`  
  Time-based LED animation over three ports: red/yellow/green-like sequence with second-level transitions. Useful as simple state indication.
- `feedback/led-touch-trigger-lightshow.c`  
  Runs a timed two-LED lightshow after touch input and stays with a fallback blink mode when idle. Useful for user feedback scripts.

#### competition
- `competition-sweep/championship-sweep-routine.c`  
  Full loop routine with manual motion stages and sensor-triggered behavior. This is a competition-style sequence you can split into smaller reusable tasks.

#### mechanism
- `mechanism/dual-shooter-joystick-control.c`  
  Button-controlled dual shooter + feeder logic: one button drives two motors, another button controls a feeder motor. Suitable for mechanism test and sequencing.

#### motion
- `motion/encoder-repeater-forward.c`  
  Repeats encoder-based forward motion steps forever. Each cycle resets encoders, sets target rotation, then waits until both stop.
- `motion/encoder-step-cycle-forward.c`  
  Same motion pattern as `encoder-repeater-forward.c`, intended as a variant for project-level reuse and quick comparison.
- `motion/step-and-rotate-encoder-profile.c`  
  Two-stage asymmetric encoder profile: first one direction gets longer command, then roles swap. Useful for checking drift, lag, and asymmetry.
- `motion/progressive-turn-distance-profile.c`  
  Short then long staged turns with different distances and speeds, useful for understanding acceleration-like behavior and heading progress.

#### navigation
- `navigation/gyro-heading-hold.c`  
  Minimal heading-hold loop: uses gyro angle as target correction and continually issues motor commands. Useful as base for self-correcting steering.
- `navigation/gyro-compass-direction-lock.c`  
  Converts gyro angle into direction labels and applies corrective motor target commands by angle sign and magnitude. Combines direction logging and correction behavior.
- `navigation/line-follow-state-machine.c`  
  Line following with an encoder checkpoint and two operational phases. Each phase applies opposite correction depending on grayscale threshold.
- `navigation/line-follow-threshold-state-switch.c`  
  Similar line follower with a fixed encoder threshold at 2800, then switches to the opposite correction strategy after crossing the checkpoint.
- `navigation/line-follow-while-threshold.c`  
  Classic loop style follow logic: while grayscale stays high/low, one side pauses while the other keeps moving, then recover to equal forward speed.
- `navigation/obstacle-reverse-on-threshold.c`  
  Keeps going while distance is safe, and reverses when threshold is crossed. Minimal obstacle escape strategy.
- `navigation/obstacle-reverse-on-threshold-long.c`  
  Long variant of obstacle recovery with extra distance sensor setup lines, keeping the same forward-reverse behavior.

#### sensors
- `sensors/telemetry/color-distance-gyro-bumper-debug.c`  
  Continuous telemetry print loop for color, distance, gyro, and bumper readings. Useful for calibration and sensor sanity check.
- `sensors/grayline-counting-by-threshold.c`  
  Threshold-based counting demo with grayscale transitions while moving. Useful for counting line-crossing-style events.

#### misc
- `misc/countdown-and-accel-demo.c`  
  Counter/display experiment code with logic that needs condition adjustment to make the loop runnable. Useful as an exercise in fixing control-flow conditions.
- `misc/task-micro-demo.c`  
  Demonstrates RobotC tasks (`task one`, `task two`) and `startTask` scheduling from `task main`.
- `misc/blank-template.c`  
  Empty project scaffold for quick starting a new RobotC sketch.

### License

This repository is released under the MIT License. See [`LICENSE`](./LICENSE).


## 中文

这是我编写的 VEX IQ RobotC 代码合集，按功能模块分类，便于学习、复用和重构。

### 使用方法

1. 安装 RobotC for VEX IQ。
2. 打开任意 `.c` 文件。
3. 按实际接线修改电机和传感器端口映射。
4. 下载到 VEX IQ 主控并测试。
5. 在正式使用前按场景调整速度、阈值和延时参数。

### 文件详细说明

#### control（控制）
- `control/touch-start-stop-winch.c`  
  触摸按下时使电机持续正转，松开即停止，属于典型的“按住运行”机构控制模板。
- `control/joystick-drive-basic.c`  
  双摇杆通道直接控制左右电机，几乎无死区处理，适合验证基础遥控映射。
- `control/joystick-drive-button-gear.c`  
  使用按键实现三种行为：左转、右转和前进，未触发时停止。适合做离散按键控制的出发模板。

#### feedback（反馈）
- `feedback/led-touch-gated-sequence.c`  
  以触摸状态为条件切换 LED 颜色（红/绿/蓝）三段序列，适合做事件触发的状态机演示。
- `feedback/led-cascade-sequence.c`  
  按固定时序输出级联 LED 动画，适用于状态显示和课程演示。
- `feedback/led-touch-trigger-lightshow.c`  
  按触摸传感器进入长短间隔灯光秀，空闲时进入蓝色循环反馈。

#### competition（赛事）
- `competition-sweep/championship-sweep-routine.c`  
  赛题风格循环动作流程，包含前进、转向与传感器触发动作。适合拆解后重组比赛任务。

#### mechanism（机构）
- `mechanism/dual-shooter-joystick-control.c`  
  双按键控制双主炮 + 送料电机（示例中的 `BtnFUp` 与 `BtnEUp`）。用于机构联动与启动节奏测试。

#### motion（运动）
- `motion/encoder-repeater-forward.c`  
  无限循环编码器前进示例，每次复位后设置目标并等待完成。
- `motion/encoder-step-cycle-forward.c`  
  与上一个逻辑一致的运动模板，作为同类项目的对照版本。
- `motion/step-and-rotate-encoder-profile.c`  
  两段式不对称角度控制，先一边长行程再换向后互换，适合测试动力差异。
- `motion/progressive-turn-distance-profile.c`  
  先短距离同步转向，后大距离非对称转向，适合观察速度和距离参数对转向曲线的影响。

#### navigation（导航）
- `navigation/gyro-heading-hold.c`  
  最简航向保持：以陀螺角度作为目标修正，持续输出修正指令。
- `navigation/gyro-compass-direction-lock.c`  
  角度分区显示方向标签，并基于正负角度进行纠偏。适合方向校正教学。
- `navigation/line-follow-state-machine.c`  
  里程阈值触发阶段切换的循线逻辑，不同阶段采用不同转向策略。
- `navigation/line-follow-threshold-state-switch.c`  
  以 2800 编码器计数为相位切点，按灰度阈值切换转向方向。
- `navigation/line-follow-while-threshold.c`  
  基础循线 while 风格：按阈值让一侧停转修正，其他侧继续前进。
- `navigation/obstacle-reverse-on-threshold.c`  
  距离安全时前进，越界后执行后退动作，属于避障行为的最小单元。
- `navigation/obstacle-reverse-on-threshold-long.c`  
  长周期版本，保留同样逻辑并加入更多距离测量配置，方便对比传感器配置。

#### sensors（传感）
- `sensors/telemetry/color-distance-gyro-bumper-debug.c`  
  实时打印色彩、距离、陀螺仪和按钮输入的串屏调试示例。
- `sensors/grayline-counting-by-threshold.c`  
  灰度阈值触发计数示例，适合训练阈值分割与事件计数。

#### misc（其他）
- `misc/countdown-and-accel-demo.c`  
  计数与显示实验草稿，当前主循环条件需要修正才会完整执行，适合作为修复练习。
- `misc/task-micro-demo.c`  
  任务并发示例：定义多个 task 并通过 `startTask` 调度。
- `misc/blank-template.c`  
  纯空白脚手架，适合快速起一个新实验。

### 开源许可

本仓库使用 MIT 协议。详见 [`LICENSE`](./LICENSE)。


### Local files not yet in repository (mapped to current naming)
- `vexiq_drive_encoder_loop.c` -> `motion/encoder-loop-forward.c`
- `vexiq_drive_eight_shape_pattern.c` -> `motion/eight-shape-pattern.c`
