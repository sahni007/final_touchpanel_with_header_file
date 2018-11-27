void actiontouchPanel(char Switch_Num, char sw_status, char speeds) //, char speeds
{
  //  TX1REG = 'P';
  //   TX1REG = Switch_Num;
        M1=ON;       M2=ON;       M3=ON;      M4=ON;       M5=ON;    M6=ON;    M7=ON;    M8=ON;
      //  TX1REG = speeds;
     //   TX1REG = Switch_Num;
        int preventFlag=0;
    int switch_status = sw_status - '0';    
     int integer_switch_speed = speeds - '0';     
     int SwNum = Switch_Num - '@';//ASCII OF SWITCH NUMBER - ASCII OF @ i.e A>>65, B>>66, C>>67, D>>68 65-64=1 and so on
  // speeds = '0';
    char ch_sw_num = SwNum +'0';//send '1' for switch A, '2' for sww2 and so on 
 //   sendFeedback_TO_Gateway(sw_status,ch_sw_num);
   if(checkFlag == TRUE )//to prevent xbee frame
    {
     //   TX1REG='T';TX1REG='1';
        checkFlag = FALSE;
        preventFlag = 2;
        
    } 
//    if(PreventFlag_ManualTo_Panel==1)//to prevent manual>>this flag set means manual is pressed but send from don't receive again 
//    {
//        TX1REG='T';TX1REG='2';
//        PreventFlag_ManualTo_Panel=0;
//    }
    if(CheckFlag2 == 1 && preventFlag!=2 )//to check is only coming from only uart2>>checkflag2>>uart2 and preventfalg>>uart1
    {
   //     TX1REG='T';TX1REG='3';
        PreventFlag_ManualTo_Panel=0;
         checkFlag=0;
        preventFlag=0;
        CheckFlag2=0;
        PreventFlag_Touch=2;
//                if(tempReceiveTouchpanelDataBuffer[0] != 'P'){
//                 __delay_ms(5);      TX1REG = 'G';
//                 __delay_ms(1);      TX1REG = sw_status;
//                 __delay_ms(1);      TX1REG = '0';
//                 __delay_ms(1);      TX1REG = Switch_Num - 16;
//                 }
//                 else
//                 {
//                 __delay_ms(5);      TX1REG = 'G';
//                 __delay_ms(1);      TX1REG = sw_status;
//                 __delay_ms(1);      TX1REG = '0';
//                 __delay_ms(1);      TX1REG = '7';    
//                 }


                 switch(Switch_Num) {

                    case 'A':
                    {
                    if(M1 == ON && copy_parentalLockBuffer[1] == CHAR_OFF )
                      {    
                            sendFeedback_TO_Gateway('1',sw_status);
                            OUTPUT_RELAY1 = switch_status;
                            M1 = OFF;
                       }
                    }

                    break;
                    case 'B':
                    {
                      if(M2 == ON && copy_parentalLockBuffer[2] == CHAR_OFF  )
                       {
                          sendFeedback_TO_Gateway('2',sw_status);
                              M2 = OFF;
                              OUTPUT_RELAY2 = switch_status;  
                       }
                    }

                    break;
                    case 'C':
                    {
                   if(M3 == ON && copy_parentalLockBuffer[3] == CHAR_OFF )
                      {
                       sendFeedback_TO_Gateway('3',sw_status);
                             OUTPUT_RELAY3 = switch_status;
                            M1 = OFF;
                       }
                    }
                    break;
                    case 'D':
                    {
                        if(M4 == ON && copy_parentalLockBuffer[4] == CHAR_OFF)
                       {
                            sendFeedback_TO_Gateway('4',sw_status);
                            M4 = OFF;
                             OUTPUT_RELAY4 = switch_status;
                      }

                    }
                    break;
                    case 'E':
                    {
                     if(M5 == ON && copy_parentalLockBuffer[5] == CHAR_OFF)
                        {
                         sendFeedback_TO_Gateway('5',sw_status);
                             M5 = OFF;
                             OUTPUT_RELAY5 = switch_status;

                       }
                    }
                    break;
                    case 'F':
                    {
                       if(M6 == ON && copy_parentalLockBuffer[6] == CHAR_OFF)
                        {
                           sendFeedback_TO_Gateway('6',sw_status);
                             M6 = OFF;
                             OUTPUT_RELAY6 = switch_status;


                       }
                    }
                    break;
                   case 'P':
                    {

                       if(M7 == ON && copy_parentalLockBuffer[7] == CHAR_OFF) {
                           sendFeedback_TO_Gateway('7',sw_status); 
                           M7 = OFF;
                         __delay_ms(1);
                         if(sw_status == '0')
                         {
                             __delay_ms(1);
                             OUTPUT_FAN_1=OFF;
                             __delay_ms(1000);
                             OUTPUT_FAN_2=OFF;
                             __delay_ms(1000);
                             OUTPUT_FAN_3=OFF;
                             __delay_ms(1000);
                         }
                        else if(sw_status == '1'){
                         if(integer_switch_speed == 1)
                         {
                               __delay_ms(1000);
                              OUTPUT_REGULATOR = ON;
                             __delay_ms(1000);
                             OUTPUT_FAN_2=OFF;
                             __delay_ms(1000);
                             OUTPUT_FAN_3=OFF;
                           __delay_ms(1000);
                              OUTPUT_FAN_1=ON;
                         }
                          if(speeds == '2')
                         {
                              __delay_ms(100);
                              OUTPUT_REGULATOR = ON;
                             __delay_ms(1000);
                             OUTPUT_FAN_1=OFF;
                             __delay_ms(1000);
                             OUTPUT_FAN_3=OFF;
                            __delay_ms(1000);
                              OUTPUT_FAN_2=ON;

                         }
                          if(integer_switch_speed == 3)
                         {

                              OUTPUT_REGULATOR = ON;
                               __delay_ms(1000);
                                OUTPUT_FAN_3=OFF;
                             __delay_ms(1000);
                              OUTPUT_FAN_1=ON;
                             __delay_ms(1000);
                             OUTPUT_FAN_2=ON;
                             __delay_ms(1000);

                         }
                          if(integer_switch_speed == 4)
                         {
                              __delay_ms(1000);
                              OUTPUT_REGULATOR = ON;
                              __delay_ms(1000);
                             OUTPUT_FAN_1=OFF;
                             __delay_ms(1000);
                             OUTPUT_FAN_2=OFF;
                             __delay_ms(1000);
                             OUTPUT_FAN_3=ON;
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
