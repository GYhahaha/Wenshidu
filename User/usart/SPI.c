/*************************************************************************/
/*函数功能: GPIO模拟SPI端口初始化                                         */
/*************************************************************************/
void OLED_SPI_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,ENABLE);//使能PA端口时钟
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4; //端口配置
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//IO口速度为50MHz
    GPIO_Init(GPIOA,&GPIO_InitStructure);//根据设定参数初始化GPIOA
}
 
/*************************************************************************/
/*函数功能: 通过SPIO软件模拟SPI通信协议,向模块(SSD1306)写入一个字节                                  */
/*入口参数：                                                                                                                          */ 
/*                      data：要写入的数据/命令                                                                       */             
/*                      cmd ：数据/命令标志 0,表示命令;1,表示数据;                   */
/*************************************************************************/
void SPI_WriteByte(unsigned char data,unsigned char cmd)
{
    unsigned char i=0;
    OLED_DC =cmd;
    OLED_CLK=0;
    for(i=0;i<8;i++)
    {
        OLED_CLK=0;
        if(data&0x80)OLED_MOSI=1; //从高位到低位
        else OLED_MOSI=0;
        OLED_CLK=1;
        data<<=1;
    }
    OLED_CLK=1;
    OLED_DC=1;
}
/*************************************************************************/
/*函数功能: 写命令                                                        */
/*************************************************************************/
void WriteCmd(unsigned char cmd)
{
    SPI_WriteByte(cmd,OLED_CMD);
}
/*************************************************************************/
/*函数功能: 写数据                                                        */
/*************************************************************************/
void WriteData(unsigned char data)
{
    SPI_WriteByte(data,OLED_DATA);
}