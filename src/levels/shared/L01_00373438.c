#include "common.h"

/* localdecomp:start func_L01_00373438 */
/* Level 1's copy of func_L39_00565860's routine: colour from a global, no size factor. */
#include "vu0.h"

typedef struct {
    f32 u, v;
} UV_00373438;

typedef struct {
    vu0_v4 v[4];
    s32 col[4];
    UV_00373438 uv[4];
    unsigned long l70, tag, l80, l88;
} S_00373438;

extern f32 func_L01_00443A18(f32, f32);
extern unsigned long func_00389598(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);
extern vu0_v4 D_L01_001E29C0;
extern f32 D_L01_001DD9E8[] __attribute__((section(".sdata")));
extern f32 D_L01_001DD9EC[] __attribute__((section(".sdata")));
extern s32 D_L01_001DD9D8;
__asm__(".extern D_L01_001DD9D8, 4");
extern s32 D_L01_001DD9E0;
__asm__(".extern D_L01_001DD9E0, 4");

void func_L01_00373438(u8 *self, vu0_v4 unused)
{
    u8 *obj = *(u8 **)(self + 0x68);
    S_00373438 s;
    vu0_v4 a, b, c, t, r;
    f32 k = 0.65f;
    f32 x;
    s32 i, col;
    s32 j;

    x = *(f32 *)(obj + 0x38);
    if (x > 32.0f) {
        k = (1.0f - (x - 32.0f) / 6.0f) * k;
        if (k < 0.001f)
            k = 0.001f;
    }

    vec_sub_ba(&c, obj, obj + 0x10);
    vec_sub_ba(&a, obj, &D_L01_001E29C0);
    vec_sub_ba(&b, obj + 0x10, &D_L01_001E29C0);
    func_0038CE90(&a, &a, &c);
    func_0038CF68(&a, &a, (func_L01_00443A18(0.1f, 0.3f) + 0.65f) * k);
    func_0038CE90(&b, &b, &c);
    func_0038CF68(&b, &b, (func_L01_00443A18(0.1f, 0.3f) + 0.65f) * k);
    s.tag = func_00389598(0x3E);
    s.l80 = 0xFF9000000260UL;
    s.l70 = 0;
    s.l88 = ((unsigned long)D_L01_001DD9D8 << 32) | 0x48;
    col = D_L01_001DD9E0;
    s.col[3] = col;
    s.col[2] = col;
    s.col[1] = col;
    s.col[0] = col;
    for (i = 0; i < 4; i++) {
        s.uv[i].u = D_L01_001DD9E8[2 * i];
        s.uv[i].v = D_L01_001DD9EC[2 * i];
    }
    vec_sub_ba(&r, obj, &a);
    s.v[0] = t = r;
    vec_add_ba(&r, obj, &a);
    s.v[1] = t = r;
    vec_sub_ba(&r, obj + 0x10, &b);
    s.v[2] = t = r;
    vec_add_ba(&r, obj + 0x10, &b);
    s.v[3] = t = r;
    func_003D2DA0(&s, 0, 0);

    vec_sub_ba(&c, obj, obj + 0x10);
    vec_sub_ba(&a, obj, &D_L01_001E29C0);
    vec_sub_ba(&b, obj + 0x10, &D_L01_001E29C0);
    func_0038CE90(&a, &a, &c);
    func_0038CF68(&a, &a, (func_L01_00443A18(0.05f, 0.15f) + 0.325f) * k);
    func_0038CE90(&b, &b, &c);
    func_0038CF68(&b, &b, (func_L01_00443A18(0.05f, 0.15f) + 0.325f) * k);
    s.tag = func_00389598(0x3F);
    s.l80 = 0xFF9000000260UL;
    s.l70 = 0;
    s.l88 = ((unsigned long)D_L01_001DD9D8 << 32) | 0x48;
    s.col[3] = 0x60DDDDDD;
    s.col[2] = 0x60DDDDDD;
    s.col[1] = 0x60DDDDDD;
    s.col[0] = 0x60DDDDDD;
    for (j = 0; j < 4; j++) {
        s.uv[j].u = D_L01_001DD9E8[2 * j];
        s.uv[j].v = D_L01_001DD9EC[2 * j];
    }
    vec_sub_ba(&r, obj, &a);
    s.v[0] = t = r;
    vec_add_ba(&r, obj, &a);
    s.v[1] = t = r;
    vec_sub_ba(&r, obj + 0x10, &b);
    s.v[2] = t = r;
    vec_add_ab(&r, obj + 0x10, &b);
    s.v[3] = t = r;
    func_003D2DA0(&s, 0, 0);
}
/* localdecomp:end func_L01_00373438 */

/* localdecomp:start func_L01_003738E0 */
void func_L01_003738E0(void *position)
{
    extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32,
        f32, f32, f32, f32,
        s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    func_L01_003303B8(position, 0, 5, 0, 5, 5, 0, 0,
        0.4f, 0.0f, 0.0f, 0.0f,
        0, 0, 0, 0, 0, 0, 0x10000, 0,
        0x00F78E38, 0x00F76300, 0x00FF7F40, 0x00FF2000,
        0x00FF8F00, 0x00FF6430, 0x7FFFA060, 0x28FF0000, 0x00FF6430, 0);
}
/* localdecomp:end func_L01_003738E0 */

/* localdecomp:start func_L01_003739B8 */
void func_L01_003739B8(void) {

}
/* localdecomp:end func_L01_003739B8 */

/* localdecomp:start func_L01_003739C0 */
typedef int Q_003739C0 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003739C0;
typedef struct {
    u8 pad0[0xBD8];
    u8 *target_now;
    u8 padBDC[0x1210 - 0xBDC];
    s32 fire_button;
    u8 pad1214[0x1430 - 0x1214];
    u8 *lockon;
    u8 pad1434[0x16B0 - 0x1434];
    s32 cam_mode;
    u8 pad16B4[0x16D4 - 0x16B4];
    s32 pulse;
    s32 alpha;
    u8 pad16DC[0x25C0 - 0x16DC];
    u8 *moby;
    s32 state;
    u8 pad25C8[0x25E9 - 0x25C8];
    u8 firing;
} H_003739C0;
extern H_003739C0 D_001A4BE0;
extern u8 D_001425C0[];
extern u8 D_00142A60[];
extern u8 D_L01_002C5600[][240];
extern u8 *D_001D52FC;
extern s32 D_L01_001E1D30;
extern s32 D_L01_001E1D34;
extern s32 D_L01_001E1D50;
extern u8 D_L01_001DDA10[] __attribute__((section(".sdata")));
extern u8 D_L01_001DDA20[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DDA10, 8");
__asm__(".extern D_L01_001DDA20, 8");
extern V_003739C0 D_L01_001E29E0;
extern u8 D_L01_002B3A40[];
void func_L01_003739C0(u8 *obj)
{
    extern void func_L01_005003D0(s32,s32);
    extern s32 func_0038CAD0(void *);
    extern void func_0038D000(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern u8 *func_L01_00450BB0(void *,void *,f32,f32,f32,f32,f32,s32);
    extern u8 *func_00382348(void *);
    extern void func_0038CE20(void *,void *,f32);
    extern s32 func_L01_004CB1F0(f32,f32);
    extern void func_L01_003F6F20(s32,void *,s32,s32,s32,s32,s32,f32,f32,f32,f32,f32,f32,f32);
    extern s32 func_L01_005118D0(s32,s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *,s32);
    extern f32 func_003824E0(f32,f32);
    extern s32 func_003A52A0(s32,s32,void *);
    extern s32 func_L01_00374790(void *,void *,void *,f32);
    extern void func_L01_00404A10(void (*)(u8 *),void *);
    extern void func_L01_00374630(u8 *);
    extern void func_L01_00373F78(u8 *);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_003F2278(s32,s32);
    extern s32 func_L01_003F1FC0(s32,s32);
    V_003739C0 pos,delta;
    u8 *p=*(u8 **)(obj+0x68);
    u8 *target,*data;
    u8 category;
    u8 *weapon;
    u8 *kind;
    u8 *tier;
    u8 *dst;
    if(obj[0x20]==0) {
        obj[0x30]=255;
        D_L01_001E1D34=0;
        *(s32 *)(p+0x58)=-1;
        obj[0x20]=1;
    }
    if(D_001A4BE0.state==1) func_L01_005003D0(29,1);
    weapon=D_L01_002C5600[D_001425C0[0x5F]];
    if(weapon[1]>=2)D_00142A60[0x5F]|=32;
    if(D_001A4BE0.lockon)D_001A4BE0.target_now=D_001A4BE0.lockon;
    func_0038CAD0(&D_L01_001E1D30);
    kind=D_L01_002C5600[D_001425C0[0x5F]];
    category=kind[1];
    if(category==3)*(s16 *)(obj+0x7C)=7;
    if(category==2)*(s16 *)(obj+0x7C)=3;
    else if(category==1)*(s16 *)(obj+0x7C)=1;
    tier=D_L01_002C5600[D_001425C0[0x5F]];
    if(tier[1]>=4)
        func_0038D000(&pos,D_L01_001DDA10,obj+0xC0);
    else func_0038D000(&pos,D_L01_001DDA20,obj+0xC0);
    vec_add_ab(&pos, &pos, obj + 0x10);
    dst=p+0x10;
    *(Q_003739C0 *)dst=*(Q_003739C0 *)&pos;
    func_0038CF68(p+0x40,obj+0xD0,-20.0f);
    func_0038CF68(p+0x30,obj+0xD0,-20.0f);
    func_0038CF68(p+0x30,p+0x30,1.0f);
    if(D_001A4BE0.lockon)target=D_001A4BE0.target_now;
    else target=func_L01_00450BB0(p+0x10,p+0x30,0.034906585f,0.034906585f,35.0f,0.05235988f,0.05235988f,1);
    if(target) {
        *(Q_003739C0 *)&delta=*(Q_003739C0 *)(target+16);
        data=func_00382348(target);
        if(data) {
            func_0038CE20(&delta,target+0xE0,*(f32 *)(data+16));
            vec_add_ba(&delta, &delta, target + 0x10);
        }
    }
    if(D_001A4BE0.state==29) {
        func_0038CF68(p+0x30,&D_L01_001E29E0,20.0f);
        vec_add_ab(p, p + 0x30, &pos);
        func_L01_003F6F20(0,obj,func_L01_004CB1F0(1.0f,150.0f),0,33,-1,4,0.8f,0.0f,90.0f,0.5f,0.5f,40.0f,40.0f);
    } else {
        D_001A4BE0.pulse=0;
        D_001A4BE0.alpha=0;
        func_0038CF68(p+0x30,D_001A4BE0.moby+0xC0,20.0f);
        vec_add_ab(p, p + 0x30, &pos);
    }
    if((*(s32 *)(D_001D52FC+0x1A4)&D_001A4BE0.fire_button) ||
       ((*(s32 *)(D_001D52FC+0x1A0)&8) && D_001A4BE0.state==29)) {
        D_L01_001E1D34++;
        *(s32 *)(p+0x54)=17;
        if(D_L01_001E1D30<=0) {
            if(func_L01_005118D0(-1,1)) {
                D_L01_001E1D50=1;
                func_L01_004EA7D8(-1);
                *(s32 *)(p+0x58)=func_L01_003F2058(D_L01_002B3A40,0);
                func_0038CF68(&delta,p+0x30,func_003824E0(60.0f,80.0f)*0.020000001f);
                func_003A52A0(1,0,obj);
                if(D_001A4BE0.cam_mode)
                    func_0038CF68(&delta,&D_L01_001E29E0,func_003824E0(60.0f,80.0f)*0.020000001f);
                func_L01_00374790(obj,p+0x10,&delta,0.5f);
                D_L01_001E1D30=25;
                func_L01_00404A10(func_L01_00374630,obj);
                func_L01_00373F78(obj);
            } else if((*(s32 *)(D_001D52FC+0x1A4)&D_001A4BE0.fire_button) || D_L01_001E1D50==1) {
                func_003A52A0(5,0,obj);
                D_L01_001E1D50=0;
            }
        }
    } else {
        func_L01_004EAA80();
        if(*(s32 *)(p+0x54)<=0)D_L01_001E1D34=0;
    }
    if(!(*(s32 *)(D_001D52FC+0x1A0)&D_001A4BE0.fire_button) || !func_L01_005119E0(-1) || !D_001A4BE0.firing) {
        if(*(s32 *)(p+0x58)<0)return;
        func_L01_003F2278(*(s32 *)(p+0x58),0);
        *(s32 *)(p+0x58)=-1;
    }
    if(*(s32 *)(p+0x58)>0 && !func_L01_003F1FC0(*(s32 *)(p+0x58)-1,0))
        *(s32 *)(p+0x58)=-1;
}
/* localdecomp:end func_L01_003739C0 */

/* localdecomp:start func_L01_00373F78 */
typedef struct { u8 p[0xD4]; u8 *a; u8 pad[0x16C - 0xD8]; u8 *b; } S_00373F78;
extern s32 D_L01_001DDA44;
__asm__(".extern D_L01_001DDA44, 4");
extern S_00373F78 D_L01_00221098;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern vu0_v4 D_001A52A0[];
void func_L01_00373F78(u8 *obj) {
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern u8 *func_L01_004660F8(void *, void *);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 step;
    vu0_v4 work;
    vu0_v4 rotation;
    vu0_v4 velocity;
    vu0_v4 axis;
    vu0_v4 temp;
    f32 spread, size, angle;
    s32 i = 0, j = 0, seed;
    u8 *particle;
    u8 *first, *second;

    pos = *(vu0_v4 *)(*(u8 **)(obj + 0x68) + 0x10);
    func_0038CE20(&off, obj + 0xD0, -0.15f);
    vec_add_ba(&pos, &pos, &off);
    func_0038CE20(&step, obj + 0xE0, 0.3f);
    vec_add_ab(&pos, &pos, &step);
    func_0038CE20(&step, obj + 0xE0, -0.033333335f);
    if (D_L01_001DDA44) {
        size = 0.4f;
        spread = 0.3f;
    } else {
        size = 0.175f;
        spread = 0.1f;
    }
    for (i = 0; i < 12; i++) {
        work.x = pos.x + func_L01_00443A18(0.0f, spread);
        work.y = pos.y + func_L01_00443A18(0.0f, spread);
        work.z = pos.z + func_L01_00443A18(0.0f, spread);
        seed = func_00382468(255);
        first = func_L01_0046FB40(&work, D_L01_001D66B0, (func_00382498(7, 12) * 5 + 2) / 6, 0x808080, seed,
                                  127, 127, size * 210000.0f, size * 210000.0f, 0.0f, 1);
        if (first) first[2] = D_L01_00221098.b[1];
        second = func_L01_0046FB40(&pos, D_L01_001D66B0, (func_00382498(7, 12) * 5 + 2) / 6, 0x203080, seed,
                                   16, 16, 472500.0f, 472500.0f, 0.0f, 1);
        if (second) second[2] = D_L01_00221098.a[0];
        vec_add_ab(&pos, &pos, &step);
    }
    work = pos;
    *(vu0_q *)&axis = 0;
    axis.x = 0.3f;
    axis.y = -1.0f;
    axis.w = 1.0f;
    func_0038D890(&axis, D_001A52A0, D_001A52A0 + 1, 0.34906584f);
    velocity = axis;
    angle = 0.0f;
    for (j = 0; j < 25; j++) {
        angle = func_0038DAB8(angle, func_003824E0(0.0f, 0.62831855f));
        func_0038CE20(&temp, &velocity, func_003824E0(0.120000005f, 0.36f));
        particle = func_L01_004660F8(&work, &temp);
        if (particle) {
            u8 *p = particle + 0x30;
            func_0038CE20(&temp, &velocity, 0.75f);
            vec_add_ab(particle + 0x10, &work, &temp);
            *(vu0_v4 *)(particle + 0x20) = work;
            *(f32 *)(p + 0xC) = 2.0f;
            *(f32 *)(particle + 0x1C) = 0.05f;
            *(f32 *)(particle + 0x2C) = 0.5f;
            *(u32 *)(particle + 4) = 0x507F7F7F;
            *(u32 *)(particle + 0xC) = 0x507F7FFF;
        }
        if (fabs_asm(angle) > 0.00001f) {
            func_003C4840(&rotation, D_001A52A0, angle);
            func_0038D850(&velocity, &axis, &rotation);
        }
    }
}
/* localdecomp:end func_L01_00373F78 */
