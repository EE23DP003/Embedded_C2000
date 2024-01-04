#include "F28x_Project.h"
void Gpio_select();
void delay_loop();

void main(void)
{

    InitSysCtrl();
    Gpio_select();
    DINT;
    while(1)
    {
        GpioDataRegs.GPATOGGLE.bit.GPIO31=1;
        GpioDataRegs.GPBTOGGLE.bit.GPIO34=1;
        delay_loop();
    }


}

    void Gpio_select(void)
    {
        EALLOW;

        GpioCtrlRegs.GPAMUX2.bit.GPIO31=0;
        GpioCtrlRegs.GPBMUX1.bit.GPIO34=0;

        GpioCtrlRegs.GPADIR.bit.GPIO31=1;
        GpioCtrlRegs.GPBDIR.bit.GPIO34=1;

        EDIS;

    }

    void delay_loop()
    {
        long i;
        for (i=0;i<1000000;i++)
        {
        }


    }



