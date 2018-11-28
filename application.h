
void applianceControl(char charSwitchMSB, char charSwitchLSB, char charSwitchSTATE, char chDimmerSpeedMSB, char chDimmerSpeedLSB,
        char charParentalControl, char charFinalFrameState){
    
    //define used variables and initilize it with zero
    int integerSwitchNumber = 0;
    int integerSwitchState = 0;
    int integerSpeed = 0;
    int currentStateBufferPositions=0;
   // TX1REG = charParentalControl;
    // Get switch Number in Integer format 
    //define all used character data types and initlize it with "#"
    char switchNumberStringBuffer[2]="#";
    char dimmerSpeedStringBuffer[2]="#";

    switchNumberStringBuffer[0]=charSwitchMSB;
    switchNumberStringBuffer[1]=charSwitchLSB;    
    integerSwitchNumber = atoi(switchNumberStringBuffer);//convert string into integer
    
    // Get switch State in Integer Format
    
    integerSwitchState = charSwitchSTATE-'0';
//    TX1REG=chDimmerSpeedMSB;
//    TX1REG=chDimmerSpeedLSB;
    // Get speed of Fan or level of dimmer    
    dimmerSpeedStringBuffer[0]=chDimmerSpeedMSB;
    dimmerSpeedStringBuffer[1]=chDimmerSpeedLSB;    
    integerSpeed = atoi(dimmerSpeedStringBuffer);
    
    // save Parental lock state of each switch into parental lock buffer
//    int integerParentalControl=charParentalControl-'0';
    parentalLockBuffer[integerSwitchNumber] = charParentalControl;
   
   
    copy_parentalLockBuffer[integerSwitchNumber]=parentalLockBuffer[integerSwitchNumber];
  //   TX1REG = parentalLockBuffer[integerSwitchNumber]; //ok same
  //   TX1REG = copy_parentalLockBuffer[integerSwitchNumber];
    
    
    // ACKNOWLEDGMENT data Format :->> (Gateway+SwitchState+SwitchMSB+SwitchLSB)
    
    currentStateBufferPositions = ((1+4*(integerSwitchNumber))-5);
    currentStateBuffer[currentStateBufferPositions++] = 'G';
    currentStateBuffer[currentStateBufferPositions++] = charSwitchSTATE;
    currentStateBuffer[currentStateBufferPositions++] = charSwitchMSB;
    currentStateBuffer[currentStateBufferPositions] = charSwitchLSB;    
    
    currentStateBufferPositions-=3;     // since we have come forward by 3 address in current state buffer
    if(charFinalFrameState=='1')    // until 
    {
        sendAcknowledgment(currentStateBuffer+currentStateBufferPositions);  
        if(integerSwitchNumber!=5){
        __delay_ms(5);
        TX2REG = '(' ;
        __delay_ms(1);
        TX2REG = TouchMatikBoardAddress ;//touchmatoc address
        __delay_ms(1);
        TX2REG =charSwitchLSB + 16 ;
        __delay_ms(1);
        TX2REG=charSwitchSTATE;
        __delay_ms(1);
        TX2REG='0';
        __delay_ms(1);
        TX2REG='0';
        __delay_ms(1);
        TX2REG='0';
        __delay_ms(1);
        TX2REG=')';
        }
        else if(integerSwitchNumber==5) {
           switch(integerSwitchState){
            case 0: {
                    send_Response_To_Touch('P','0','0');  
                   } break;
           
            case 1: {
                switch(chDimmerSpeedMSB){
                    case '0':
                    {
                    send_Response_To_Touch('P','1','1'); //SPEED1
                    }
                    break;
                    case '2':
                    {
                      send_Response_To_Touch('P','1','1');  //SPEED1
                    }
                    break;
                    case '5':
                    {
                      send_Response_To_Touch('P','1','2'); //SPEED2
                    }
                    break;
                    case '7':
                    {
                      send_Response_To_Touch('P','1','3');  //SPEED3
                    }
                    break;
                    case '9':
                    {
                      send_Response_To_Touch('P','1','4'); //SPEED4
                
                    }
                    break;
                    default:
                    break;
            }//close of switch
        }
      }
    }
  }
    
    switch(integerSwitchNumber){
        case 1:
        {
             RELAY1 = integerSwitchState;
        }
            break;
        case 2:
            {
              RELAY2 = integerSwitchState;

            break;
            }
        case 3:
        {
            RELAY3 = integerSwitchState;
        }
            break;
        case 4:
        {
            RELAY4 = integerSwitchState;
        }
            break;
        case 5:
        {
        if(integerSwitchState==0){  
                
                FAN1=OFF;
                __delay_ms(1000);
                FAN2=OFF;
                __delay_ms(1000);
                FAN3=OFF;
                 }
        else if(integerSwitchState==1)
                    {  
               
                       if(chDimmerSpeedMSB == '0')             // speed 1
                        {
                                 
                                  FAN3=OFF;
                                  __delay_ms(1000);
                                  FAN2=OFF;
                                  __delay_ms(1000);
                                  FAN1=ON;

                          }
                        else if(chDimmerSpeedMSB == '2')             // speed 1
                        {
                                  
                                  FAN3=OFF;
                                  __delay_ms(1000);
                                  FAN2=OFF;
                                  __delay_ms(1000);
                                  FAN1=ON;

                          }
                       else if(chDimmerSpeedMSB == '5')         // speed 2
                              {
                                  
                                  FAN1=OFF;
                                  __delay_ms(1000);
                                  FAN3=OFF;               
                                  __delay_ms(1000);
                                  FAN2=ON;
                              }

                          else if( chDimmerSpeedMSB=='7')      // speed 3
                              {    
                                  
                                  FAN3=OFF;
                                  __delay_ms(1000);
                                  FAN2=ON;
                                  __delay_ms(1000);
                                  FAN1=ON;
                              }
                      else if( chDimmerSpeedMSB == '9')                         // speed 4
                              {   

                                  
                                  REGULATOR=ON; 
                                  __delay_ms(1000);
                                  FAN1=OFF;//OFF;
                                  __delay_ms(1000);
                                  FAN2=OFF;//OFF;
                                 __delay_ms(1000);
                                  FAN3=ON;
                              }
                     }       

        }
            break;
        default:
            break;
        }
    
}
