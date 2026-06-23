# vexiq-robotc-code

## English

This repository collects my VEX IQ RobotC programs, organized by robot behavior so they can be reused for learning, calibration, and competition prototyping.

## What’s in this repository

- `competition/` for contest-style routines
- `control/` for manual motion control
- `motion/` for encoder/drive pattern movement
- `navigation/` for steering, line-following, and obstacle logic
- `sensors/` for telemetry/counting/debug behavior
- `feedback/` for LEDs and timed indications
- `mechanism/` and `misc/` for subsystem or template examples

## How to use

1. Open RobotC for VEX IQ.
2. Open one `.c` file.
3. Match ports and motor mapping to your actual robot wiring.
4. Compile and upload to your VEX IQ Brain.
5. Tune speeds, thresholds, and delays for your specific chassis.

## Detailed catalog (English then Chinese per file)

### competition
- `competition-sweep/championship-sweep-routine.c` — EN: A sequential match-like routine combining forward, turns, and sensor waits using motors and sensors, designed as a reusable sweep template. CN: 比赛式流程示例，包含前进、转向与传感器等待逻辑，适合作为赛事程序框架。

### control
- `control/touch-start-stop-winch.c` — EN: Uses a touch sensor on port 7 as an emergency start/stop gate: run motor while pressed, stop when released. CN: 触摸按下时运行电机、松开立即停止，适合起停机构。
- `control/joystick-drive-basic.c` — EN: Direct joystick drive mapping (`ChA`, `ChD`) into left/right motor speed values. CN: 直接使用摇杆通道驱动左右电机，适合验证手柄映射和比例控制。
- `control/joystick-drive-button-gear.c` — EN: Button-first control layer where different keys map to turn/drive states, with joystick fallback on one key. CN: 按键控制转向与前进，未按键时停机，作为离散挡位手控模板。

### feedback
- `feedback/led-touch-gated-sequence.c` — EN: Gated LED sequence (`red -> green -> blue`) controlled by touch-LED state transitions. CN: 基于触摸LED状态推进颜色阶段，演示状态触发反馈。
- `feedback/led-cascade-sequence.c` — EN: Repeated multi-port LED color cascade with timed transitions for status indication. CN: 多端口渐进式灯效序列，适合显示阶段状态。
- `feedback/led-touch-trigger-lightshow.c` — EN: Interactive lightshow tied to touch input; otherwise stays in a low-energy standby color state. CN: 触摸触发灯光秀，空闲时进入备用蓝色状态。

### mechanism
- `mechanism/dual-shooter-joystick-control.c` — EN: Button-driven mechanism control: one button runs twin shooter motors, another drives feeder motor. CN: 按键驱动双轮发射+送料，便于单元联调。

### motion
- `motion/encoder-loop-forward.c` — EN: Endless encoder loop that repeatedly commands equal targets on both wheels and waits for completion. CN: 无限循环前进里程模板，左右轮同步到达目标值后继续。
- `motion/encoder-repeater-forward.c` — EN: Similar to loop-forward, wrapped as a repeatable cycle with explicit motor/encoder setup. CN: 重复执行编码器前进的重复版，含驱动和编码器的标准配置。
- `motion/encoder-step-cycle-forward.c` — EN: Step-based forward cycle using encoder checkpoints and `waitUntil` completion calls. CN: 编码器分段到位前进程序。
- `motion/eight-shape-pattern.c` — EN: Two-motor target profile that generates alternating distance patterns resembling an “8” path. CN: 通过交替设置左右轮目标脉冲形成“8”形运动轨迹。
- `motion/step-and-rotate-encoder-profile.c` — EN: Multi-stage encoder sequence with swapped distances on left/right motor roles. CN: 两阶段里程/转向组合，左右轮目标互换以测试对称性。
- `motion/progressive-turn-distance-profile.c` — EN: Combines short/long turn segments with varying distances and speed to approximate progressive motion shaping. CN: 渐进转向示例，包含短段和长段转向与速度差异。

### navigation
- `navigation/gyro-heading-hold.c` — EN: Very compact heading-hold loop using gyro value as motor target correction. CN: 极简航向保持循环，利用陀螺角度修正。
- `navigation/gyro-compass-direction-lock.c` — EN: Compass-like gyro sector detection plus correction routine, with LED status output per angle region. CN: 根据陀螺角落区分方向，结合颜色LED给出方位提示和纠偏。
- `navigation/line-follow-state-machine.c` — EN: Two-phase line-following with encoder gate and while-loop state transitions. CN: 带编码器阈值的两阶段循线状态机。
- `navigation/line-follow-threshold-state-switch.c` — EN: Threshold-based line follow that switches correction behavior after left-motor encoder reaches 2800 counts. CN: 灰度阈值循线，在左轮计数到达2800后切换策略。
- `navigation/line-follow-while-threshold.c` — EN: While-loop line follower that pivots one side based on grayscale threshold continuously. CN: 纯while方式循线：按阈值让一侧轮子停转并修正。
- `navigation/obstacle-reverse-on-threshold.c` — EN: Moves forward while distance is safe, reverses on threshold breach. CN: 距离安全前进，触发阈值后后退。
- `navigation/obstacle-reverse-on-threshold-long.c` — EN: Extended long-horizon obstacle routine with multiple distance sensor declarations for broader compatibility. CN: 加强版障碍处理示例，保留两套距离配置。

### sensors
- `sensors/sensor-multi-read-debug.c` — EN: Multi-channel sensor debug loop printing grayscale, distance, gyro, and touch values continuously. CN: 多传感器实时调试示例，持续打印灰度、距离、陀螺和触摸值。
- `sensors/telemetry/color-distance-gyro-bumper-debug.c` — EN: Continuous real-time debug stream for color, distance, gyro, and touch values. CN: 实时串屏调试模板，持续打印色值、距离、角速度/角度和触摸值。
- `sensors/grayline-counting-by-threshold.c` — EN: Threshold-based grayscale counter with repeated runs for line-counting experiments. CN: 灰度阈值计数教学例子，适合计数线段交叉事件。

### misc
- `misc/blank-template.c` — EN: Empty RobotC scaffold with `task main()` only, intended as a clean starting point. CN: 空白骨架文件，适合快速创建新任务。
- `misc/countdown-and-accel-demo.c` — EN: Countdown/telemetry-style loop example with counter progression and display output. CN: 倒计时与显示示例。
- `misc/task-micro-demo.c` — EN: Demonstrates two worker tasks and `startTask` usage from `task main()`. CN: 任务并行结构示例，展示 `task one`, `task two` 与主任务调度。

## License

This repository is released under the MIT License. See [`LICENSE`](./LICENSE).

## 中文

这是我自己的 VEX IQ RobotC 代码合集，按行为模块分类，便于复用、课程演示和竞赛工程拆解。

## 使用方式

1. 安装 RobotC for VEX IQ。
2. 打开任意 `.c` 文件。
3. 按实物接线修改端口与电机映射。
4. 下载到 VEX IQ Brain 后调参。
5. 通过阈值、速度、延时逐步适配你的机器人。

## 详细目录（先英文后中文）

### 赛事（competition）
- `competition-sweep/championship-sweep-routine.c` — EN: A full routine loop combining chassis movement, sensor checks, and task switching, built as a competition-oriented scaffold. CN: 赛事风格完整动作链，包含传感器判断与重复流程，适合作竞赛程序拆解。

### 控制（control）
- `control/touch-start-stop-winch.c` — EN: Touch-gated motor start/stop example for lifting or winch-like mechanics. CN: 触摸按钮控制的“按住运行、松开停止”模板。
- `control/joystick-drive-basic.c` — EN: Direct left-right tank control through joystick channels. CN: 摇杆通道直连左右电机映射示例。
- `control/joystick-drive-button-gear.c` — EN: Button-mode joystick demo with separate forward/left/right mappings and off state fallback. CN: 按键离散档位控制示例，未输入时默认停止。

### 反馈（feedback）
- `feedback/led-touch-gated-sequence.c` — EN: Touch-sensitive LED step sequence, useful for event-driven state displays. CN: 触发式的LED颜色状态序列。
- `feedback/led-cascade-sequence.c` — EN: Time-based cascade animation across three LED outputs. CN: 三路LED级联、计时切换的显示效果。
- `feedback/led-touch-trigger-lightshow.c` — EN: Touch start enters light animation, otherwise stays in standby. CN: 触摸启动的灯光秀，空闲时退回常态。

### 机构（mechanism）
- `mechanism/dual-shooter-joystick-control.c` — EN: Joystick-button control for dual shooter + feeder subsystem. CN: 双主炮与送料组件的按键联动示例。

### 运动（motion）
- `motion/encoder-loop-forward.c` — EN: Repeatable encoder loop for stable forward distance control. CN: 无限循环的编码器前进基线。
- `motion/encoder-repeater-forward.c` — EN: Repeater pattern that resets each cycle and uses encoder targets. CN: 每轮重置/前进的重复式编码器程序。
- `motion/encoder-step-cycle-forward.c` — EN: Step-cycle motion variant using both motor targets and encoder waits. CN: 里程分步的编码器推进版本。
- `motion/eight-shape-pattern.c` — EN: Motor profile intended to reproduce an “8” movement shape. CN: 通过两轮目标脉冲构成8字路径。
- `motion/step-and-rotate-encoder-profile.c` — EN: Two asymmetrical steps with motor role swap for turning and direction comparison. CN: 两段式转动与速度对比。
- `motion/progressive-turn-distance-profile.c` — EN: Progressive forward/turn sequence with distance and speed progression. CN: 多级距离与速度递进转向。

### 导航（navigation）
- `navigation/gyro-heading-hold.c` — EN: Minimal heading hold loop. CN: 最小化航向保持实现。
- `navigation/gyro-compass-direction-lock.c` — EN: Region-based gyro direction lock with correction and LED output. CN: 按角度区间进行方位显示与纠偏控制。
- `navigation/line-follow-state-machine.c` — EN: Stateful line-follow demo switching phases by encoder threshold. CN: 以编码器相位切换的循线状态机。
- `navigation/line-follow-threshold-state-switch.c` — EN: Fixed-threshold state switch version of line following, with phase crossing at 2800 counts. CN: 编码器达到2800后切换循线策略。
- `navigation/line-follow-while-threshold.c` — EN: Continuous while-loop line correction by grayscale comparison. CN: while循环永动的阈值循线控制。
- `navigation/obstacle-reverse-on-threshold.c` — EN: Distance threshold safety gate with forward/reverse fallback. CN: 基本避障反向回退。
- `navigation/obstacle-reverse-on-threshold-long.c` — EN: Long-threshold variant with extra distance configuration lines for robustness. CN: 长循环障碍示例，保留多个距离配置。

### 传感（sensors）
- `sensors/sensor-multi-read-debug.c` — EN: Continuous debug stream for grayscale, distance, gyro, and touch channels using a simple repeat loop. CN: 简单的多传感器连续调试循环，按行显示灰度、距离、陀螺与触摸数值。
- `sensors/telemetry/color-distance-gyro-bumper-debug.c` — EN: Real-time telemetry printer for four sensor channels. CN: 四通道传感器实时调试显示。
- `sensors/grayline-counting-by-threshold.c` — EN: Threshold crossing counter sample for line counting and repeat loops. CN: 灰度阈值事件计数演示。

### 其他（misc）
- `misc/blank-template.c` — EN: Blank template project skeleton. CN: 空白RobotC模板。
- `misc/countdown-and-accel-demo.c` — EN: Counter and update example with timing prints and loop control. CN: 计数与显示逻辑示例。
- `misc/task-micro-demo.c` — EN: Demonstrates `startTask` and concurrent task style in RobotC. CN: 任务并发模型示例。

## 开源许可

本仓库使用 MIT 协议，详见 [`LICENSE`](./LICENSE)。
