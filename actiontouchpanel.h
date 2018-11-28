#void actiontouchPanel(char Switch_Num, char sw_status, char Sw_speed) //, char speeds
{

     M1=ON;M2=ON;M3=ON;M4=ON;  M5=ON; M6=ON; M7=ON; M8=ON;

    int switch_status = sw_status - '0';        
    int SwNum = Switch_Num - '@';//ASCII OF SWITCH NUMBER - ASCII OF @ i.e A>>65, B>>66, C>>67, D>>68 65-64=1 and so on
    int int_swSpeed = Sw_speed-'0';
    char ch_sw_num = SwNum +'0';//send '1' for switch A, '2' for sww2 and so on 
    
 if(checkFlag == TRUE)  
  
 {  
     checkFlag=FALSE;   
 }   
    else
    {
 //    TX1REG='T';
        switch(Switch_Num)
        {

               case 'A':
               {
               if(copy_parentalLockBuffer[1] == CHAR_OFF && M1 == ON)
                  {
                       sendFeedback_TO_Gateway('1',sw_status);
                       RELAY1 = switch_status; M1 = OFF;

                  }
               }

               break;
               case 'B':
               {

                 if( copy_parentalLockBuffer[2] == CHAR_OFF && M2 == ON  )
                  {       
                        sendFeedback_TO_Gateway('2',sw_status);
                         RELAY2 = switch_status;  M2 = OFF;

                  }

               }

               break;
               case 'C':
               {
              if( copy_parentalLockBuffer[3] == CHAR_OFF && M3 == ON )
                 {    
                    sendFeedback_TO_Gateway('3',sw_status);
                     RELAY3 = switch_status;
                       M3 = OFF;
                  }

               }
               break;
               case 'D':
               {
                   if(copy_parentalLockBuffer[4] == CHAR_OFF && M4 == ON  )
                  {
                       sendFeedback_TO_Gateway('4',sw_status);
                        RELAY4 = switch_status;M4 = OFF;
                 }

               }
               break;
            case 'P':
             {
                        if(copy_parentalLockBuffer[5]==CHAR_OFF && M5==ON )
                        {
                            sendFeedback_TO_Gateway('5',sw_status);
                                M5=OFF;
                                if(switch_status == 0)
                                {
                                     REGULATOR = ON;
                                     __delay_ms(1000);
                                    FAN1=OFF;
                                    __delay_ms(1000);
                                    FAN2=OFF;
                                    __delay_ms(1000);
                                    FAN3=OFF;
                                    __delay_ms(1000);

                                }
                               else if(switch_status == 1)
                                    {

                                        if(Sw_speed == '1')
                                        {
                                            
                                             REGULATOR = ON;
                                             __delay_ms(1000);             
                                            FAN1=ON;
                                            __delay_ms(1000);
                                            FAN2=OFF;
                                            __delay_ms(1000);
                                            FAN3=OFF;
                                        }
                                         else if(Sw_speed == '2')
                                        {
                                              
                                             REGULATOR = ON;
                                             __delay_ms(1000);
                                            FAN1=OFF;
                                            __delay_ms(1000);
                                            FAN3=OFF;
                                            __delay_ms(1000);
                                            FAN2=ON;

                                        }
                                         else if(Sw_speed == '3')
                                        {
                                             
                                             REGULATOR = ON;
                                             __delay_ms(1000);
                                            FAN3=OFF;
                                            __delay_ms(1000);
                                            FAN2=ON;
                                            __delay_ms(1000);
                                            FAN1=ON;
                                            __delay_ms(1000);
                                        }
                                         else if(Sw_speed == '4')
                                        {
                                              
                                             REGULATOR = ON;
                                             __delay_ms(1000);
                                            FAN1=OFF;
                                            __delay_ms(1000);
                                            FAN2=OFF;
                                            __delay_ms(1000);
                                            FAN3=ON;
                                        }
                                    }
                        }

            }
            break;
             default:
             break;
        }
    }       
}

        
