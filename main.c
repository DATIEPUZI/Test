#include "common.h"
#include "include.h"

/*先初始化连接蓝牙的串口，发送一个字节直接调用uart_putchar (UARTn_e uratn, char ch);
**接收一个字节开中断后在中断里接收
**
*/
/*
void uart0_handler(void)
{
	uart_rx_irq_dis(UART0);										//关接收中断
	
	char ch;
    UARTn_e uratn = UART0;

    if(UART_S1_REG(UARTN[uratn]) & UART_S1_RDRF_MASK)   		//接收数据寄存器满
    {      
        uart_getchar(UART0, &ch);                    			
		if(ch=='b')											   	//如果接收到确认字符
		{
			uart_putstr (UART3, "1234567");					//发个数据到电脑，指示蓝牙收发正常
			gpio_turn (PTA17);										//控制小灯闪烁，指示程序运行正常
		}
		//可以在这儿根据收到的信息对小车做一些调整		
    }  
	
	uart_rx_irq_en (UART0); 									//开接收中断
}


void main()
{	
	gpio_init (PTA17, GPO, 0);									//PORT里能设置GPIO的各种功能，但不能设置GPIO的数据方向，GPIO里能
	port_init (PTA17, HDS|ALT1 );             					//PTA17 复用为GPIO，推挽输出
	
	uart_init (UART0, 9600);									//初始化串口UART0


	set_vector_handler(UART0_RX_TX_VECTORn,uart0_handler);   	// 设置中断复位函数到中断向量表里
	uart_rx_irq_en(UART0);										//开串口接收中断
	
	while(1)
	{	
	  	uart_putchar (UART0,'a');								//蓝牙连在UART0，发送字符a(串口UART0被我用作printf的端口号了，一开始就被初始化了，这里不用再初始化)
						
//	  	gpio_turn (PTA17);										//控制小灯闪烁，指示程序运行正常
		systick_delay_ms(500);      							//这里 的延时 ，仅仅是 避免 过于频繁打印数据到串口		
	}
}

*/








//加接收中断，可以在一收到数据时就对小车做出调整，若用查询接收则只能一次循环接收一次。也因此，对小车做出调整要在中断里，否则和查询接收时效性一样
void uart0_handler(void)
{
	uart_rx_irq_dis(UART0);
	gpio_turn (PTA17);										//控制小灯闪烁，指示程序运行正常
	char ch;
    UARTn_e uratn = UART0;

    if(UART_S1_REG(UARTN[uratn]) & UART_S1_RDRF_MASK)   		//接收数据寄存器满
    {      
        uart_getchar(UART0, &ch);                    			
		if(ch=='a')											   	//如果接收到一个字符，并且接受到的字符是a
		{
			uart_putchar (UART0,'b');						   	//确认收到数据后发送一个确认字符
		}
		//可以在这儿根据收到的信息对小车做一些调整		
    }  
	
	uart_rx_irq_en (UART0); 
}



void main()
{	
	gpio_init (PTA17, GPO, 0);									//PORT里能设置GPIO的各种功能，但不能设置GPIO的数据方向，GPIO里能
	port_init (PTA17, HDS|ALT1 );             					//PTA17 复用为GPIO，推挽输出
	
	uart_init (UART0, 9600);									//初始化串口UART0
	
	set_vector_handler(UART0_RX_TX_VECTORn,uart0_handler);   	// 设置中断复位函数到中断向量表里
	uart_rx_irq_en(UART0);										//开串口接收中断
										
	while(1)
	{		
//	  	gpio_turn (PTA17);										//控制小灯闪烁，指示程序运行正常
//		systick_delay_ms(500);      							//这里 的延时 ，仅仅是 避免 过于频繁打印数据到串口		
	}
}

