###

```markdown
# Smart Pressure Sensory & Visual Alert System (智能压力感知与分级视觉预警系统)

An Arduino-based edge-computing prototype that captures analog physical signals via a Force Sensitive Resistor (FSR) and performs real-time, multi-stage visual alerting.

这是一个基于 Arduino UNO 的边缘计算交互原型。系统通过柔性压阻传感器（FSR）捕获微小的物理压力变化，经过本地信号处理与自适应阈值判定，实现毫伏级响应的绿/红双级视觉预警回馈。

---

##  项目核心卖点 (Core Features)

- **高灵敏边缘计算 (Edge Computing):** 信号在本地微处理器（Arduino）完成采样与实时控制，延迟低于 30ms，具备极高的实时性。
- **自适应多级交互 (Multi-stage Feedback):**
  - **静息态 (Standby):** 无外力触发，系统低功耗待命，灯光熄灭。
  - **常态协同 (Normal - 绿灯):** 捕获轻微动作信号，绿灯亮起，提示系统正常工作并捕获有效行为。
  - **风险预警 (Warning - 红灯):** 当外力超过安全阈值（如阻力过大或异常痉挛），系统立即切断绿灯并强制触发红灯，实现闭环预警。
- **高信噪比架构 (High SNR Layout):** 采用精密分压电路设计，基底噪声极低，抗干扰能力强。

---

## 硬件清单 (Bill of Materials)

| 序号 | 元件名称 | 规格/型号 | 数量 | 作用 |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 微控制器 | Arduino UNO R3 (或兼容板) | 1 | 核心控制大脑、数据处理 |
| 2 | 压力传感器 | FSR 柔性薄膜压阻传感器 | 1 | 压力信号采集 |
| 3 | 信号分压电阻 | 10kΩ 直插电阻 (四环/五环) | 1 | 建立分压电路，将电阻变化转为电压变化 |
| 4 | 限流电阻 | 220Ω 直插电阻 | 2 | 保护 LED，防止电流过大烧毁 |
| 5 | 发光二极管 | 5mm LED (红、绿各一) | 2 | 分级交互视觉状态指示 |
| 6 | 实验板 | 标准等长面包板 | 1 | 硬件电路免焊免线搭建 |
| 7 | 连接线 | 导电杜邦线 (公对公) | 若干 | 电路各节点信号互连 |

---

##  目录结构 (Repository Structure)

```text
smart-pressure-sensor/
├── firmware/
│   └── Smart_Pressure_Indicator.ino   # Arduino 源代码（主程序）
├── docs/
│   └── Wiring_Guide.md                 # 详细硬件接线指南与引脚对照
└── README.md                           # 项目开源主说明文档
