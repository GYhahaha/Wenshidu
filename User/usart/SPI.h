#define OLED_CMD 0   //命令声明
#define OLED_DATA 1 //数据声明

#define OLED_CLK    PAout(4)    // CLK时钟    d0
#define OLED_MOSI   PAout(3)    // MOSI     d1
#define OLED_RST    PAout(2)    // RET复位    ret
#define OLED_DC     PAout(1)    // 命令|数据    dc  （0表传输命令1表传输数据）

void OLED_SPI_Init(void); //配置MCU的SPI
void SPI_WriteByte(uint8_t addr,uint8_t data); //向寄存器地址写一个byte的数据
void WriteCmd(unsigned char cmd); //写命令
void WriteDat(unsigned char data); //写数据