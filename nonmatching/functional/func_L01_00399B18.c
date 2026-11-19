/* functional: high. 143-word diff is allocation/scheduling; every constant, call argument and offset re-read against retail asm. */
#include "common.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_0039E0C8;
/* localdecomp:start func_L01_00399B18 */
typedef struct { u8 pad[0x5C]; u8 *type; } State_00399B18;
extern State_00399B18 D_L01_00221098;
extern f32 D_001A4EC0[];
void func_L01_00399B18(u8 *obj, s128_003985C0 *position) {
    extern void func_0038CF68(Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0013D3E0(void);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);
    s128_003985C0 origin, velocity, current, step;
    s32 count, kind, i;
    s32 life, texture, mode;
    u32 color;
    f32 speed;
    u8 *particle;
    f32 length = *(f32 *)(*(u8 **)(obj+0x68)+0x18);
    origin = *position;
    current = origin;
    count = (s32)(length / 0.15f);
    vec_sub_ab(&step, obj+0x10, &origin);
    func_0038CF68((Vec4_0039E0C8 *)&step, (Vec4_0039E0C8 *)&step, length / count);
    kind = D_L01_002C5600[D_001425FF[0]].pad[1];
    for (i=count; i>0; i--) {
        mode = (s32)func_L01_00443A18(1.0f,3.0f);
        func_0038CE20((f32 *)&velocity,D_001A4EC0,-(func_003824E0(0.2f,1.0f)*0.020000001f));
        life = func_00382498(30,55);
        speed = func_003824E0(200.0f,1000.0f);
        if (func_0013D3E0() & 2) {
            texture=64;
            color=0;
            speed+=speed;
        } else {
            texture=80;
            color=0x7F7F7F;
            if (kind) color=0x104080;
        }
        particle=func_L01_0046A610(&current,&velocity,(life*5+2)/6,texture,color,mode,31500.002f,speed,1.0f,0.0f,0.0f);
        vec_add_ab(&current,&current,&step);
        if (particle) {
            particle[2]=*D_L01_00221098.type;
            particle[3]=texture==80?0x48:0x44;
        }
    }
}
/* localdecomp:end func_L01_00399B18 */
