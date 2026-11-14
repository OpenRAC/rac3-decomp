#include "common.h"

/* NTSC-U counterpart of func_L06_0032DF80 (src/levels/06_starship_phoenix_under_attack/L06_0032DF80.c) */
/* localdecomp:start func_L06_0032D7B8 */
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
extern unsigned char D_L06_001DE7E4_0032D7B8;
extern unsigned char D_L06_001DE7E5_0032D7B8;
extern unsigned char D_L06_001DE7E6_0032D7B8;
extern float D_001DCDD8_sda;
extern float D_001DCDDC_sda;
extern int D_001D545C;
extern unsigned char D_001BBC40[];

__asm__(".extern D_001426F4, 16");
__asm__(".extern D_001DCDD8_sda, 4");
__asm__(".extern D_001DCDDC_sda, 4");

extern void func_L06_0032DAA8(void);
extern void func_L06_0032DAD8(Obj_0032DF80 *);
extern void func_L06_0032D990(Obj_0032DF80 *);
extern void func_L01_00441FB8(Obj_0032DF80 *, int, int);
extern void func_L01_004A6D70(int, Obj_0032DF80 *);
extern void func_0039FE80(int, int, Obj_0032DF80 *);
extern void func_00399F90(void);
extern int func_L01_004B6C68(void);
extern int func_L01_00452EC8(Obj_0032DF80 *);

void func_L06_0032D7B8(Obj_0032DF80 *o) {
    State_0032DF80 *s = o->state;
    int mode;

    func_L06_0032DAA8();
    mode = o->mode;
    switch (mode) {
    case 0:
        if (D_001426F4[0]) {
            func_L01_00441FB8(o, 2, -1);
        } else {
            s->time = 0;
            func_L01_00441FB8(o, 1, -1);
        }
        s->active = 1;
        s->field_0F = 255;
        s->field_0C = 0;
        break;
    case 1:
        s->time += D_001DCDD8_sda;
        if (s->time >= D_001DCDDC_sda + 1.0f) {
            s->time -= D_001DCDDC_sda + 1.0f;
            func_L01_004A6D70(0, o);
            s->active = mode;
        }
        if (s->time > D_001DCDDC_sda && !func_L01_004B6C68()) {
            if (s->active) {
                func_0039FE80(0, 0x35, o);
                s->active = 0;
            }
        }
        if (D_001BBC40[s->index + D_001D545C * 16] & 0x80) {
            D_001426F4[0] = 1;
            func_00399F90();
            func_L01_00441FB8(o, 2, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(o)) {
            func_L06_0032D990(o);
            D_L06_001DE7E4_0032D7B8 = 0;
            D_L06_001DE7E5_0032D7B8 = 0;
            D_L06_001DE7E6_0032D7B8 = 0;
        }
    }
    func_L06_0032DAD8(o);
}
/* localdecomp:end func_L06_0032D7B8 */
