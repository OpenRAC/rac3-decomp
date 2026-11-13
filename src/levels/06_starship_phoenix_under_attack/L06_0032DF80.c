#include "common.h"

/* localdecomp:start func_L06_0032DF80 */
typedef struct {
    char pad_00[0xC];
    short field_0C;
    char pad_0E;
    unsigned char field_0F;
    int index;
    float time;
    unsigned char active;
} State_0032DF80;

typedef struct {
    char pad_00[0x20];
    unsigned char mode;
    char pad_21[0x47];
    State_0032DF80 *state;
} Obj_0032DF80;

extern unsigned char D_001426F4[];
extern unsigned char D_L06_001DE7E4;
extern unsigned char D_L06_001DE7E5;
extern unsigned char D_L06_001DE7E6;
extern float D_001DCD98_sda;
extern float D_001DCD9C_sda;
extern int D_001D545C;
extern unsigned char D_001BBC40[];

__asm__(".extern D_001426F4, 16");
__asm__(".extern D_001DCD98_sda, 4");
__asm__(".extern D_001DCD9C_sda, 4");

extern void func_L06_0032E280(void);
extern void func_L06_0032E2B0(Obj_0032DF80 *);
extern void func_L06_0032E168(Obj_0032DF80 *);
extern void func_L01_004450F0(Obj_0032DF80 *, int, int);
extern void func_L01_004AA760(int, Obj_0032DF80 *);
extern void func_003A52A0(int, int, Obj_0032DF80 *);
extern void func_0039EF28(void);
extern int func_L01_004BA800(void);
extern int func_L01_004561B8(Obj_0032DF80 *);

void func_L06_0032DF80(Obj_0032DF80 *o) {
    State_0032DF80 *s = o->state;
    int mode;

    func_L06_0032E280();
    mode = o->mode;
    switch (mode) {
    case 0:
        if (D_001426F4[0]) {
            func_L01_004450F0(o, 2, -1);
        } else {
            s->time = 0;
            func_L01_004450F0(o, 1, -1);
        }
        s->active = 1;
        s->field_0F = 255;
        s->field_0C = 0;
        break;
    case 1:
        s->time += D_001DCD98_sda * 1.2f;
        if (s->time >= D_001DCD9C_sda + 1.0f) {
            s->time -= D_001DCD9C_sda + 1.0f;
            func_L01_004AA760(0, o);
            s->active = mode;
        }
        if (s->time > D_001DCD9C_sda && !func_L01_004BA800()) {
            if (s->active) {
                func_003A52A0(0, 0x35, o);
                s->active = 0;
            }
        }
        if (D_001BBC40[s->index + D_001D545C * 16] & 0x80) {
            D_001426F4[0] = 1;
            func_0039EF28();
            func_L01_004450F0(o, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(o)) {
            func_L06_0032E168(o);
            D_L06_001DE7E4 = 0;
            D_L06_001DE7E5 = 0;
            D_L06_001DE7E6 = 0;
        }
    }
    func_L06_0032E2B0(o);
}
/* localdecomp:end func_L06_0032DF80 */
