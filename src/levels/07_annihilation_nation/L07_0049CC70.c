#include "common.h"

/* localdecomp:start func_L07_0049CC70 */
typedef struct { s32 exists; s32 f4,f8; u32 *data; u32 kind; u8 active; u8 pad[3]; } Row_0049CC70;
extern Row_0049CC70 D_L07_002EE6A8[];
extern u32 D_00142BA0[];
extern s32 D_L07_001D9418;
extern u8 D_00142693[];
void func_L07_0049CC70(void) {
    s32 i=0;
    while(D_L07_002EE6A8[i].exists) {
        switch(D_L07_002EE6A8[i].kind) {
        case 1: {
            s32 n=0;
            Row_0049CC70 *r=&D_L07_002EE6A8[i];
            r->active=1;
            while(D_L07_002EE6A8[i].data[n]) {
                s32 active=0;
                if ((r->active && (D_00142BA0[D_L07_002EE6A8[i].data[n]>>2] & (1 << (D_L07_002EE6A8[i].data[n]&31)))) || D_L07_001D9418) active=1;
                r->active=active;
                n++;
            }
            break;
        }
        case 0:
        case 2: {
            u32 bit=(u32)D_L07_002EE6A8[i].data;
            Row_0049CC70 *r=&D_L07_002EE6A8[i];
            s32 active=0;
            if((D_00142BA0[bit>>2] & (1 << (bit&31))) || D_L07_001D9418) active=1;
            r->active=active;
            break;
        }
        case 3: {
            Row_0049CC70 *r=&D_L07_002EE6A8[i];
            s32 active=0;
            if(D_00142693[0] || D_L07_001D9418) active=1;
            r->active=active;
            break;
        }
        case 4:
        default: D_L07_002EE6A8[i].active=1; break;
        }
        i++;
    }
}
/* localdecomp:end func_L07_0049CC70 */
