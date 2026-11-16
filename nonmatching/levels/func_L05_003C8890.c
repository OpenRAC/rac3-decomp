/* NTSC-U draft (Codex wave 3): C of func_L05_003C6778, the NTSC-U twin of func_L05_003C8890, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 93 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L05_003C6778", whose code is not the PAL one).
 * Worker's note: 93 diff; best log w148/func_L05_003C6778.01.log; position/colour spill allocation, init store order and particle induction remain; indexed loops, postincrement arguments, increment ordering, earlier owner store and long counter not closer; 9 compiles; ...
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L05_003C6778 */
extern void func_003BFC18(void *, void *, s32);
typedef struct { vu0_v4 direction, velocity; s32 life, a24,a28; f32 amount; s32 owner, other; } State133;
typedef struct { u8 pad0[0x10]; vu0_v4 position; u8 state; u8 pad21[0xb]; f32 scale; u8 alpha,b31; s16 render; u16 flags; u8 pad36[0x32]; State133 *vars; u8 pad6c[0x54]; vu0_v4 right,up,forward; } Object133;
extern Object133 *func_003BCFB0(s32,s32);
extern void func_L01_00440A88(void *,f32,f32);
extern f32 func_0037E250(f32,f32);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern void func_00388830(void *,void *,f32);
extern void func_00388758(void *,void *,void *);
extern void func_L01_00467DA8(void *,s32,f32,f32,s32,s32,s32,void *,f32,s32);
extern void func_L01_0046D570(void *,s32,f32,f32,s32,s32,s32,void *,s32,s32,s16,s32);
extern s32 D_001DECB0_sda[2];
extern f32 D_001DECD0_sda[2];
extern f32 D_001DECF0_sda[2];
extern s32 D_001DED10_sda[2];
__asm__(".extern D_001DECB0_sda, 8");
__asm__(".extern D_001DECD0_sda, 8");
__asm__(".extern D_001DECF0_sda, 8");
__asm__(".extern D_001DED10_sda, 8");
extern vu0_v4 D_L05_001D66B0;
Object133 *func_L05_003C6778(s32 arg0,s32 arg1,vu0_v4 *position,vu0_v4 *direction,f32 amount) {
    vu0_v4 normal, temp;
    Object133 *obj;
    State133 *s;
    f32 angle;
    s32 i, j;
    f32 *sizes, *starts;
    s32 *colours;
    func_003BFC18(position,&normal,1);
    obj=func_003BCFB0(0x1C33,0x80);
    if (obj) {
        s=obj->vars;
        obj->flags|=0x100;
        s->life=300;
        obj->scale=0.003f;
        obj->alpha=255;
        obj->render=255;
        obj->state=0;
        *(vu0_q *)&obj->position=*(vu0_q *)position;
        *(vu0_q *)&s->direction=*(vu0_q *)direction;
        s->other=arg1;
        starts=D_001DECF0_sda;
        sizes=D_001DECD0_sda;
        colours=D_001DECB0_sda;
        func_L01_00440A88(&s->velocity,0.2f,1.0f);
        angle=func_0037E250(-1000.0f,1000.0f)*0.0174532924f*0.0166666675f;
        func_00388830(&s->velocity,&s->velocity,func_00388978(angle));
        s->velocity.w=func_00388960(angle);
        s->amount=amount;
        s->a28=0;
        s->a24=0;
        func_00388830(&temp,direction,1.0f);
        *(vu0_q *)&obj->right=*(vu0_q *)&temp;
        func_00388758(&obj->up,&obj->right,&normal);
        func_00388830(&obj->up,&obj->up,1.0f);
        func_00388758(&obj->forward,&obj->up,&obj->right);
        obj->right.w=obj->up.w=obj->forward.w=0.0f;
        s->owner=arg0;
        for(i=3;i>=0;i--,colours++,sizes++,starts++) {
            func_L01_00467DA8(position,14,*sizes,*starts,*colours,2,1,&D_L05_001D66B0,0.0f,1);
        }
        for(j=4;j<=6;j++) {
            func_L01_0046D570(position,20,D_001DECD0_sda[j],D_001DECF0_sda[j],D_001DECB0_sda[j],2,2,&D_L05_001D66B0,0,D_001DED10_sda[j-4],6,1);
        }
    }
    return obj;
}
/* localdecomp:end func_L05_003C6778 */
