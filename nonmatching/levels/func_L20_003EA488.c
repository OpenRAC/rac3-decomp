/* PAL near miss: 20 differing instruction words with the owning file's flags,
 * improved from 27 by giving the second UV/colour loop its own counter.
 * Remaining differences: phase temporary f3 versus f1, the first draw loop's
 * pointer/count initialization order, and second UV-loop register allocation.
 * The owning source remains assembly.
 */
#include "common.h"
/* localdecomp:start func_L20_003EA488 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_003EA488;
extern f32 D_L20_001DF23C;
extern s32 D_L20_001DF244, D_L20_001DF248, D_L20_001DF24C, D_L20_001DF250, D_L20_001DF254;
extern f32 D_L20_001DF258;
extern f32 D_L20_001DF260[];
__asm__(".extern D_L20_001DF260, 4");
extern f32 D_L20_001DF264[] __attribute__((section(".sdata")));
__asm__(".extern D_L20_001DF23C, 4");
__asm__(".extern D_L20_001DF244, 4");
__asm__(".extern D_L20_001DF248, 4");
__asm__(".extern D_L20_001DF24C, 4");
__asm__(".extern D_L20_001DF250, 4");
__asm__(".extern D_L20_001DF254, 4");
__asm__(".extern D_L20_001DF258, 4");
void func_L20_003EA488(void *obj) {
    void func_0038D570(void *, void *);
    void func_0038D328(void *, void *);
    unsigned long func_00389598(s32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    void func_0038D5F0(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_003D93B0(void *, s32, s32, s32);
    Q_003EA488 q[3];
    vu0_v4 matrix[4], rotation[4];
    vu0_v4 axis, a,b;
    u8 *m = obj;
    u8 *vars = *(u8 **)(m+0x68);
    f32 fade, phase, offset, angle, nextAngle, radius;
    s32 i,j,count,color;
    *(vu0_q *)&axis = 0;
    axis.z = 0.2617994f;
    func_0038D570(matrix, *(u8 **)(m+0xB8)+0xC0);
    *(vu0_q *)&matrix[3] = *(vu0_q *)(m+0x10);
    matrix[3].w = 1.0f;
    func_0038D328(rotation,&axis);
    fade = (D_L20_001DF23C - *(f32 *)(vars+0x1C)) * 0.5f;
    phase = *(f32 *)(vars+0x20) - (s32)*(f32 *)(vars+0x20);
    if (fade > 1.0f) fade = 1.0f;
    else if (fade < 0.0f) fade = 0.0f;
    for (i=0; i<3; i++) {
        f32 angle, nextAngle, radius;
        q[i].u78 = func_00389598(D_L20_001DF24C);
        q[i].u80 = 0xFF9000000260UL;
        q[i].u70 = 5;
        q[i].gif = ((unsigned long)D_L20_001DF250 << 2) | ((unsigned long)D_L20_001DF254 << 6) | (0x8000UL << 24);
        radius = *(f32 *)(vars+0x1C) - i * 0.05f;
        angle = i * 0.08726646f;
        nextAngle = func_0038DAB8(angle,0.2617994f);
        a.x = func_0038D098(angle)*radius;
        a.y = func_0038D0B0(angle)*radius;
        a.z = 0;
        a.w = 1;
        b.x = func_0038D098(nextAngle)*radius;
        b.y = func_0038D0B0(nextAngle)*radius;
        b.z = 0;
        b.w = 1;
        offset = phase * (D_L20_001DF258 + func_L01_00443A18(0.2f,0.6f));
        *(vu0_q *)&q[i].v[0] = *(vu0_q *)&a;
        q[i].v[0].z = offset;
        *(vu0_q *)&q[i].v[1] = *(vu0_q *)&a;
        q[i].v[1].z = -offset;
        *(vu0_q *)&q[i].v[2] = *(vu0_q *)&b;
        q[i].v[2].z = offset;
        *(vu0_q *)&q[i].v[3] = *(vu0_q *)&b;
        q[i].v[3].z = -offset;
        color = func_0038DBD8(D_L20_001DF248,D_L20_001DF244,(1.0f-phase)*fade);
        for (j=0;j<4;j++) {
            q[i].col[j] = color;
            q[i].uv[j][0] = D_L20_001DF260[j*2];
            q[i].uv[j][1] = D_L20_001DF264[j*2];
        }
        { f32 next;
        if (phase >= 0.666f) next = phase + -0.666f;
        else next = phase + 0.333f;
        phase = next; }
    }
    count = 23;
    do {
        func_0038D5F0(matrix,matrix,rotation);
        func_003D2DA0(&q[0],(s32)matrix,1);
        func_003D2DA0(&q[1],(s32)matrix,1);
        func_003D2DA0(&q[2],(s32)matrix,1);
    } while (--count >= 0);
    for (i=0;i<3;i++) {
        f32 fi;
        func_003D93B0(&q[i],D_L20_001DF24C,3,0x80);
        fi = i;
        radius = *(f32 *)(vars+0x1C) - fi * 0.05f;
        angle = fi * 0.08726646f;
        nextAngle = func_0038DAB8(angle,0.2617994f);
        a.x = func_0038D098(angle)*radius;
        a.y = func_0038D0B0(angle)*radius;
        a.z = 0;
        a.w = 1;
        b.x = func_0038D098(nextAngle)*radius;
        b.y = func_0038D0B0(nextAngle)*radius;
        b.z = 0;
        b.w = 1;
        offset = phase * 0.75f;
        *(vu0_q *)&q[i].v[0] = *(vu0_q *)&a;
        q[i].v[0].z = offset;
        *(vu0_q *)&q[i].v[1] = *(vu0_q *)&a;
        q[i].v[1].z = -offset;
        *(vu0_q *)&q[i].v[2] = *(vu0_q *)&b;
        q[i].v[2].z = offset;
        *(vu0_q *)&q[i].v[3] = *(vu0_q *)&b;
        q[i].v[3].z = -offset;
        { s32 k;
        for (k=0;k<4;k++) {
            q[i].col[k] = 0x7F7F7F7F;
            q[i].uv[k][0] = D_L20_001DF260[k*2];
            q[i].uv[k][1] = D_L20_001DF264[k*2];
        }
        }
        { f32 next;
        if (phase >= 0.666f) next = phase + -0.666f;
        else next = phase + 0.333f;
        phase = next; }
    }
    count = 23;
    do {
        func_0038D5F0(matrix,matrix,rotation);
        func_003D2DA0(&q[0],(s32)matrix,1);
        func_003D2DA0(&q[1],(s32)matrix,1);
        func_003D2DA0(&q[2],(s32)matrix,1);
    } while (--count >= 0);
}
/* localdecomp:end func_L20_003EA488 */
