#include "common.h"
#include "include.h"

/*�ȳ�ʼ�����������Ĵ��ڣ�����һ���ֽ�ֱ�ӵ���uart_putchar (UARTn_e uratn, char ch);
**����һ���ֽڿ��жϺ����ж������
**
*/
/*
void uart0_handler(void)
{
	uart_rx_irq_dis(UART0);										//�ؽ����ж�
	
	char ch;
    UARTn_e uratn = UART0;

    if(UART_S1_REG(UARTN[uratn]) & UART_S1_RDRF_MASK)   		//�������ݼĴ�����
    {      
        uart_getchar(UART0, &ch);                    			
		if(ch=='b')											   	//������յ�ȷ���ַ�
		{
			uart_putstr (UART3, "1234567");					//�������ݵ����ԣ�ָʾ�����շ�����
			gpio_turn (PTA17);										//����С����˸��ָʾ������������
		}
		//��������������յ�����Ϣ��С����һЩ����		
    }  
	
	uart_rx_irq_en (UART0); 									//�������ж�
}


void main()
{	
	gpio_init (PTA17, GPO, 0);									//PORT��������GPIO�ĸ��ֹ��ܣ�����������GPIO�����ݷ���GPIO����
	port_init (PTA17, HDS|ALT1 );             					//PTA17 ����ΪGPIO���������
	
	uart_init (UART0, 9600);									//��ʼ������UART0


	set_vector_handler(UART0_RX_TX_VECTORn,uart0_handler);   	// �����жϸ�λ�������ж���������
	uart_rx_irq_en(UART0);										//�����ڽ����ж�
	
	while(1)
	{	
	  	uart_putchar (UART0,'a');								//��������UART0�������ַ�a(����UART0��������printf�Ķ˿ں��ˣ�һ��ʼ�ͱ���ʼ���ˣ����ﲻ���ٳ�ʼ��)
						
//	  	gpio_turn (PTA17);										//����С����˸��ָʾ������������
		systick_delay_ms(500);      							//���� ����ʱ �������� ���� ����Ƶ����ӡ���ݵ�����		
	}
}

*/








//�ӽ����жϣ�������һ�յ�����ʱ�Ͷ�С���������������ò�ѯ������ֻ��һ��ѭ������һ�Ρ�Ҳ��ˣ���С����������Ҫ���ж������Ͳ�ѯ����ʱЧ��һ��
void uart0_handler(void)
{
	uart_rx_irq_dis(UART0);
	gpio_turn (PTA17);										//����С����˸��ָʾ������������
	char ch;
    UARTn_e uratn = UART0;

    if(UART_S1_REG(UARTN[uratn]) & UART_S1_RDRF_MASK)   		//�������ݼĴ�����
    {      
        uart_getchar(UART0, &ch);                    			
		if(ch=='a')											   	//������յ�һ���ַ������ҽ��ܵ����ַ���a
		{
			uart_putchar (UART0,'b');						   	//ȷ���յ����ݺ���һ��ȷ���ַ�
		}
		//��������������յ�����Ϣ��С����һЩ����		
    }  
	
	uart_rx_irq_en (UART0); 
}



void main()
{	
	gpio_init (PTA17, GPO, 0);									//PORT��������GPIO�ĸ��ֹ��ܣ�����������GPIO�����ݷ���GPIO����
	port_init (PTA17, HDS|ALT1 );             					//PTA17 ����ΪGPIO���������
	
	uart_init (UART0, 9600);									//��ʼ������UART0
	
	set_vector_handler(UART0_RX_TX_VECTORn,uart0_handler);   	// �����жϸ�λ�������ж���������
	uart_rx_irq_en(UART0);										//�����ڽ����ж�
										
	while(1)
	{		
//	  	gpio_turn (PTA17);										//����С����˸��ָʾ������������
//		systick_delay_ms(500);      							//���� ����ʱ �������� ���� ����Ƶ����ӡ���ݵ�����		
	}
}

