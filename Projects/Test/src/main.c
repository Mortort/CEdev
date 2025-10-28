#include <ti/screen.h>
#include <stdlib.h>
#include <graphx.h>
#include <keypadc.h>
#include <stdbool.h>


bool *getKey(){
    kb_Scan();
    bool KeyUp = kb_Data[7] & kb_Up;
    bool KeyDown = kb_Data[7] & kb_Down;
    bool KeyLeft = kb_Data[7] & kb_Left;
    bool KeyRight = kb_Data[7] & kb_Right;

    static bool Keys[4];
    
    Keys[0] = KeyUp;
    Keys[1] = KeyDown;
    Keys[2] = KeyLeft;
    Keys[3] = KeyRight;

    return Keys;
}

/* Main function, called first */
int main(void)
{
    kb_Scan();
    uint8_t ScreenColor = 0;

    /* Clear the homescreen
    Start Graphix rendering*/
    os_ClrHome();
    gfx_Begin();


    while (true)
    {
        if (kb_Data[6] & kb_Clear){
            break;
        }

        bool *arrows = getKey();
        int colors[] = {0,127,92,204};

        for(int i = 0; i<=3;i++){
            if (arrows[i])
            {
                ScreenColor = colors[i];
                break;
            }
            
        }

        gfx_FillScreen(ScreenColor);
        gfx_SwapDraw();
    }

    /* Stop Graphix rendering
    Return 0 for success */
    gfx_End();
    return 0;
}
