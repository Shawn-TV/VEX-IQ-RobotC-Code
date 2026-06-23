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

## Detailed catalog (English)

### competition
- `competition-sweep/championship-sweep-routine.c`
  - A sequential match-like routine combining forward, turns, and sensor waits using motors and sensors, designed as a reusable sweep template.

### control
- `control/touch-start-stop-winch.c`
  - Uses a touch sensor on port 7 as an emergency start/stop gate: run motor while pressed, stop when released.
- `control/joystick-drive-basic.c`
  - Direct joystick drive mapping (`ChA`, `ChD`) into left/right motor speed values.
- `control/joystick-drive-button-gear.c`
  - Button-first control layer where different keys map to turn/drive states, with joystick fallback on one key.

### feedback
- `feedback/led-touch-gated-sequence.c`
  - Gated LED sequence (`red -> green -> blue`) controlled by touch-LED state transitions.
- `feedback/led-cascade-sequence.c`
  - Repeated multi-port LED color cascade with timed transitions for status indication.
- `feedback/led-touch-trigger-lightshow.c`
  - Interactive lightshow tied to touch input; otherwise stays in a low-energy standby color state.

### mechanism
- `mechanism/dual-shooter-joystick-control.c`
  - Button-driven mechanism control: one button runs twin shooter motors, another drives feeder motor.

### motion
- `motion/encoder-loop-forward.c`
  - Endless encoder loop that repeatedly commands equal targets on both wheels and waits for completion.
- `motion/encoder-repeater-forward.c`
  - Similar to loop-forward, wrapped as a repeatable cycle with explicit motor/encoder setup.
- `motion/encoder-step-cycle-forward.c`
  - Step-based forward cycle using encoder checkpoints and `waitUntil` completion calls.
- `motion/eight-shape-pattern.c`
  - Two-motor target profile that generates alternating distance patterns resembling an “8” path.
- `motion/step-and-rotate-encoder-profile.c`
  - Multi-stage encoder sequence with swapped distances on left/right motor roles.
- `motion/progressive-turn-distance-profile.c`
  - Combines short/long turn segments with varying distances and speed to approximate progressive motion shaping.

### navigation
- `navigation/gyro-heading-hold.c`
  - Very compact heading-hold loop using gyro value as motor target correction.
- `navigation/gyro-compass-direction-lock.c`
  - Compass-like gyro sector detection plus correction routine, with LED status output per angle region.
- `navigation/line-follow-state-machine.c`
  - Two-phase line-following with encoder gate and while-loop state transitions.
- `navigation/line-follow-threshold-state-switch.c`
  - Threshold-based line follow that switches correction behavior after left-motor encoder reaches 2800 counts.
- `navigation/line-follow-while-threshold.c`
  - While-loop line follower that pivots one side based on grayscale threshold continuously.
- `navigation/obstacle-reverse-on-threshold.c`
  - Moves forward while distance is safe, reverses on threshold breach.
- `navigation/obstacle-reverse-on-threshold-long.c`
  - Extended long-horizon obstacle routine with multiple distance sensor declarations for broader compatibility.

### sensors
- `sensors/sensor-multi-read-debug.c`
  - Multi-channel sensor debug loop printing grayscale, distance, gyro, and touch values continuously.
- `sensors/telemetry/color-distance-gyro-bumper-debug.c`
  - Continuous real-time debug stream for color, distance, gyro, and touch values.
- `sensors/grayline-counting-by-threshold.c`
  - Threshold-based grayscale counter with repeated runs for line-counting experiments.

### misc
- `misc/blank-template.c`
  - Empty RobotC scaffold with `task main()` only, intended as a clean starting point.
- `misc/countdown-and-accel-demo.c`
  - Countdown/telemetry-style loop example with counter progression and display output.
- `misc/task-micro-demo.c`
  - Demonstrates two worker tasks and `startTask` usage from `task main()`.

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

## 详细目录（中文）

### 赛事（competition）
- `competition-sweep/championship-sweep-routine.c`
  - 赛事风格完整动作链，包含传感器判断与重复流程，适合作竞赛程序拆解。

### 控制（control）
- `control/touch-start-stop-winch.c`
  - 触摸按钮控制的“按住运行、松开停止”模板。
- `control/joystick-drive-basic.c`
  - 摇杆通道直连左右电机映射示例。
- `control/joystick-drive-button-gear.c`
  - 按键离散档位控制示例，未输入时默认停止。

### 反馈（feedback）
- `feedback/led-touch-gated-sequence.c`
  - 触发式的LED颜色状态序列。
- `feedback/led-cascade-sequence.c`
  - 三路LED级联、计时切换的显示效果。
- `feedback/led-touch-trigger-lightshow.c`
  - 触摸启动的灯光秀，空闲时退回常态。

### 机构（mechanism）
- `mechanism/dual-shooter-joystick-control.c`
  - 双主炮与送料组件的按键联动示例。

### 运动（motion）
- `motion/encoder-loop-forward.c`
  - 无限循环的编码器前进基线。
- `motion/encoder-repeater-forward.c`
  - 每轮重置/前进的重复式编码器程序。
- `motion/encoder-step-cycle-forward.c`
  - 里程分步的编码器推进版本。
- `motion/eight-shape-pattern.c`
  - 通过两轮目标脉冲构成8字路径。
- `motion/step-and-rotate-encoder-profile.c`
  - 两段式转动与速度对比。
- `motion/progressive-turn-distance-profile.c`
  - 多级距离与速度递进转向。

### 导航（navigation）
- `navigation/gyro-heading-hold.c`
  - 最小化航向保持实现。
- `navigation/gyro-compass-direction-lock.c`
  - 按角度区间进行方位显示与纠偏控制。
- `navigation/line-follow-state-machine.c`
  - 以编码器相位切换的循线状态机。
- `navigation/line-follow-threshold-state-switch.c`
  - 编码器达到2800后切换循线策略。
- `navigation/line-follow-while-threshold.c`
  - while循环永动的阈值循线控制。
- `navigation/obstacle-reverse-on-threshold.c`
  - 基本避障反向回退。
- `navigation/obstacle-reverse-on-threshold-long.c`
  - 长循环障碍示例，保留多个距离配置。

### 传感（sensors）
- `sensors/sensor-multi-read-debug.c`
  - 简单的多传感器连续调试循环，按行显示灰度、距离、陀螺与触摸数值。
- `sensors/telemetry/color-distance-gyro-bumper-debug.c`
  - 四通道传感器实时调试显示。
- `sensors/grayline-counting-by-threshold.c`
  - 灰度阈值事件计数演示。

### 其他（misc）
- `misc/blank-template.c`
  - 空白RobotC模板。
- `misc/countdown-and-accel-demo.c`
  - 计数与显示逻辑示例。
- `misc/task-micro-demo.c`
  - 任务并发模型示例。

## 开源许可

本仓库使用 MIT 协议，详见 [`LICENSE`](./LICENSE)。
