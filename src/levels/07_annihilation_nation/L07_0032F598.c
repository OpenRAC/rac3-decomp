#include "common.h"

/* localdecomp:start func_L07_0032F598 */
extern u8 D_L07_002B0D40_0032F598[];
extern f32 D_L07_001DED50;
extern f32 D_001A4C60[];
extern u8 D_001A4BE0[];
extern s32 D_L07_001DF41C;
extern u16 D_001A7466[];
extern f32 D_001A7404[];
void func_L07_0032F598(u8 *obj) {
    extern void func_L07_0032F988(u8 *);
    extern void func_L07_0032FDC8(u8 *);
    extern void func_L01_0042B068(s32,s32);
    extern void func_L07_003309A0(u8 *);
    extern void func_L01_00479280(void);
    extern s32 func_L01_0047B420(void);
    extern void func_L01_0047B990(void);
    extern void func_L01_005003D0(s32,s32);
    extern void func_L07_00330828(u8 *);
    extern void func_L07_003323F8(u8 *);
    extern void func_L07_00332098(u8 *);
    extern void func_L07_00331BB0(u8 *);
    extern void func_L07_00331EE8(u8 *);
    extern void func_L01_004450F0(void *,s32,s32);
    extern void func_L07_00331288(s32);
    extern f32 func_L01_0040E548(void *,void *);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_L03_0032FB70(f32);
    extern s32 func_L07_003B1578(void *);
    extern f32 func_0038DBA0(f32,f32);
    extern s32 func_L07_003326D8(u8 *);
    extern s32 func_L07_00331FA0(u8 *);
    extern s32 func_L07_00331600(u8 *);
    extern void func_L07_00330AA0(u8 *);
    extern void func_L07_00335230(u8 *);
    extern void func_L07_00330F30(u8 *);
    extern s32 func_L01_00456250(u8 *);
    extern void func_L07_00330F98(s32);
    u8 *vars;
    f32 distance, angle;
    s32 sector, index;
    if (!obj[0x20]) func_L07_0032F988(obj);
    func_L07_0032FDC8(obj);
    vars=*(u8 **)(obj+0x68);
    switch(obj[0x20]) {
    case 1: break;
    case 2:
        if (D_L07_001DED50<1.0f) D_L07_001DED50+=0.09600000083446503f;
        else {
            D_L07_001DED50=1.0f;
            func_L01_0042B068(1,0);
            func_L07_003309A0(obj);
        }
        break;
    case 3:
        D_L07_001DED50-=0.09600000083446503f;
        if (D_L07_001DED50<=0.0f) {
            D_L07_001DED50=0;
            func_L01_00479280();func_L01_0047B420();func_L01_0047B990();
            func_L01_005003D0(0,1);
            func_L07_00330828(obj);
        }
        break;
    case 4:
        func_L07_003323F8(obj);func_L07_00332098(obj);func_L07_00331BB0(obj);func_L07_00331EE8(obj);
        func_L01_004450F0(obj,5,-1);
        break;
    case 5:
        if (++*(u16 *)(obj+0x96)>=31) { func_L07_00331288((s32)obj);*(u16 *)(obj+0x96)=0; }
        distance=func_L01_0040E548(D_001A4C60,obj+0x10);
        if (distance>576.0f && distance<615.0399780273438f) {
            u8 *hero=(u8 *)D_001A4C60-0x80;
            angle=func_0038D160(*(f32 *)(hero+0x80)-*(f32 *)(obj+0x10),*(f32 *)(hero+0x84)-*(f32 *)(obj+0x14));
            sector=((s32)(func_L03_0032FB70(func_0038DAB8(angle,0.39269909262657166f))/0.39269909262657166f))>>1;
            if ((sector&3)!=2) {
                if (sector<7) index=sector-(sector>=3);
                else index=sector-2;
                if (func_L07_003B1578((void *)(D_L07_001DF41C+(*(s32 *)((s32)vars+(index<<2))<<8)))) {
                    if(func_0038DBA0(angle,(f32)sector*0.785398006439209f)<0.12217304855585098f) D_001A7466[0]=*(u16 *)(vars+0x7C);
                }
            }
        }
        if(func_L07_003326D8(obj)) break;
        if(func_L07_00331FA0(obj)) break;
        func_L01_004450F0(obj,6,-1);
        break;
    case 6:
        if (++*(u16 *)(obj+0x96)>=31) { func_L07_00331288((s32)obj);*(u16 *)(obj+0x96)=0; }
        if(func_L07_00331600(obj)) break;
        func_L01_004450F0(obj,7,-1);
        break;
    case 7:
        if(vars[0x9F]<*(s16 *)(D_L07_002B0D40_0032F598+vars[0x9E]*16)-1) {
            func_L07_00330AA0(obj);
            func_L01_004450F0(obj,4,-1);
        } else {
            if(!vars[0xAA]) func_L07_00335230(obj);
            vars[0xA8]=0;
            func_L07_00330F30(obj);
        }
        break;
    case 8:
        D_001A7404[0]=200.0f;
        if(func_L01_00456250(obj)) {
            func_L07_00330F98((s32)obj);
            func_L01_004450F0(obj,1,-1);
        }
        break;
    }
}
/* localdecomp:end func_L07_0032F598 */

/* localdecomp:start func_L07_0032F988 */
typedef struct {
    s32 ids[7]; s32 groups[7]; s32 single[3]; s32 more[3]; s32 doors[8];
    void *data; u8 gap74[0x4B]; u8 flag;
} V_0032F988;
extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458;
extern u8 D_L07_001DD104;
__asm__(".extern D_L07_001DD104, 1");
extern u8 D_001426E0[];
extern s32 D_00142848[];
extern s32 *func_L07_00333918(void *);
extern s32 *func_L07_00333B20(void *);
extern s32 *func_L07_00333B68(void *);
extern void func_L07_003328D0(s32);
extern void func_L07_00332BE0(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_0032F988(u8 *self) {
    V_0032F988 *v = *(V_0032F988 **)(self + 0x68);
    s32 i, k, j, m, d;
    for (i = 0; i < 7; i++) {
        if (i != 3 && i != 4) {
            u16 *p;
            for (p = D_L07_0021C020[v->groups[i]];
                 (v->groups[i] & 0xFF) != 0xFF && v->groups[i] <= D_L07_001DF458 && p &&
                 ((s16)p[-1] >= 0 || p == D_L07_0021C020[v->groups[i]]); p++) {
                u8 *obj = (u8 *)D_L07_001DF41C + ((*p & 0x7FFF) << 8);
                if (!obj) break;
                *(s16 *)(obj + 0x32) = 150;
                obj[0x30] = 150;
                *(u8 **)func_L07_00333918(obj) = self;
                if (i == 2 || i == 5 || i == 6) obj[0x62] = 0;
            }
        }
    }
    for (k = 0; k < 3; k++) {
        u8 *obj = (u8 *)D_L07_001DF41C + (v->single[k] << 8);
        *(s16 *)(obj + 0x32) = 150;
        obj[0x30] = 150;
        *(u8 **)func_L07_00333918(obj) = self;
    }
    for (j = 0; j < 3; j++) {
        u16 *p;
        for (p = D_L07_0021C020[v->more[j]];
             (v->more[j] & 0xFF) != 0xFF && v->more[j] <= D_L07_001DF458 && p &&
             ((s16)p[-1] >= 0 || p == D_L07_0021C020[v->more[j]]); p++) {
            u8 *obj = (u8 *)D_L07_001DF41C + ((*p & 0x7FFF) << 8);
            if (!obj) break;
            *(s16 *)(obj + 0x32) = 150;
            obj[0x30] = 150;
            *(u8 **)func_L07_00333B20(obj) = self;
        }
    }
    for (m = 0; m < 6; m++) {
        u8 *obj = (u8 *)D_L07_001DF41C + (v->ids[m] << 8);
        *(s16 *)(obj + 0x32) = 150;
        obj[0x30] = 150;
        *(u8 **)func_L07_00333B68(obj) = self;
    }
    {
        u8 *obj = (u8 *)D_L07_001DF41C + (v->ids[6] << 8);
        *(s16 *)(obj + 0x32) = 150;
        obj[0x30] = 150;
        *(u8 **)func_L07_00333B68(obj) = self;
    }
    for (d = 0; d < 8; d++) {
        u8 *obj = (u8 *)D_L07_001DF41C + (v->doors[d] << 8);
        *(s16 *)(obj + 0x32) = 150;
        obj[0x30] = 150;
    }
    if (D_L07_001DD104) {
        v->flag = 1;
        func_L07_003328D0((s32)self);
        D_L07_001DD104 = 0;
    }
    if (D_001426E0[0xE3]) {
        s32 n = D_001426E0[0xE3];
        D_001426E0[0xE3] = 0;
        D_00142848[0] = n - 1;
    }
    v->data = 0;
    func_L07_00332BE0(self);
    *(u16 *)(self + 0x34) |= 1;
    func_L01_004450F0(self, 1, -1);
}
/* localdecomp:end func_L07_0032F988 */

INCLUDE_ASM("asm/levels", func_L07_0032FDC8);

/* localdecomp:start func_L07_003303B0 */
typedef struct {
    u8 pad0[4];
    u8 *f4;
    u8 pad1[8];
} T_003303B0;

typedef struct {
    u8 pad0[9];
    u8 f9;
    u8 fA;
    u8 pad1[1];
} E_003303B0;

typedef struct {
    float x;
    float y;
    float z;
} F_003303B0;

typedef struct {
    u8 pad0[0x70];
    F_003303B0 *f70;
    u8 pad1[0x2A];
    u8 f9E;
    u8 f9F;
} V_003303B0;

typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x47];
    V_003303B0 *f68;
} O_003303B0;

extern T_003303B0 D_L07_002B0D40[];
extern void *func_L01_003F2A50(s32, s32);
extern void func_L01_003F2AF8(s32, void *);

void func_L07_003303B0(O_003303B0 *arg0) {
    V_003303B0 *s;
    E_003303B0 *e;

    s = arg0->f68;
    if (arg0->f20 >= 2) {
        if (s->f70 == 0) {
            s->f70 = func_L01_003F2A50(0, 5);
        } else {
            e = (E_003303B0 *)(D_L07_002B0D40[s->f9E].f4 + s->f9F * 12);
            if (e->f9 != 0) {
                s->f70->x = 8.0f;
                s->f70->y = 4.0f;
                s->f70->z = 3.0f;
            } else if (e->fA != 0) {
                s->f70->x = 8.0f;
                s->f70->y = 6.0f;
                s->f70->z = 3.0f;
            } else {
                s->f70->x = 8.0f;
                s->f70->y = 4.0f;
                s->f70->z = 1.0f;
            }
        }
    } else {
        if (s->f70 != 0) {
            func_L01_003F2AF8(0, s->f70);
            s->f70 = 0;
        }
    }
}
/* localdecomp:end func_L07_003303B0 */

/* localdecomp:start func_L07_003304C0 */
extern u8 D_001A4BE0[];
extern s32 D_001D545C_sda;
extern u8 D_0014275B[];
extern f32 D_001DA970_sda;
extern f32 D_L07_002F3450[];
typedef struct {
    u8 pad[0xC0];
    f32 c0, c4;
    s32 c8;
    f32 cc;
    s16 d0,d2,d4,d6,d8;
    u8 pda[5];
    u8 df;
} State_003304C0;
typedef struct { u8 pad[0x25C4]; s32 state; u8 p[0x2850-0x25C8]; s32 health; } Hero_003304C0;
void func_L07_003304C0(u8 *obj) {
    extern s32 func_L07_003C1AF8(void);
    extern f32 func_L07_003C1B40(s32);
    extern s32 func_L01_0041A4F0(void);
    extern void func_L07_00334B68(void *);
    extern void func_L07_00334BA8(void *);
    extern void func_L07_00334BE8(void *);
    extern void func_L07_00334C28(void *);
    extern s32 func_L07_00334EC0(void *);
    extern s32 func_L07_003A24C8(void);
    extern s32 func_00382468(s32);
    extern s32 func_0038CB00(void *);
    State_003304C0 *s = *(State_003304C0 **)(obj + 0x68);
    f32 scale;
    if ((u32)(obj[0x20]-4) >= 4) return;
    if ((*(Hero_003304C0 *)D_001A4BE0).state == 116) return;
    scale=func_L07_003C1B40(func_L07_003C1AF8());
    if (func_L01_0041A4F0()) {
        f32 factor;
        if (D_001D545C_sda == 7 && D_0014275B[0]) factor=D_001DA970_sda;
        else factor=D_L07_002F3450[D_001D545C_sda];
        scale*=factor;
    }
    if (!s->d4 && s->cc > 3.0f) {
        func_L07_00334B68(obj);
        s->d4=func_00382468(1000)+2000;
        s->cc=0.0f;
    }
    if (!s->d2 && s->c4 > scale*20.0f) {
        func_L07_00334BA8(obj);
        s->d2=func_00382468(1000)+2000;
        s->c4=0.0f;
    }
    if (!s->d0 && ((f32)s->c8 > 10.0f || s->c0 > scale*40.0f)) {
        func_L07_00334BE8(obj);
        s->d0=func_00382468(1000)+2000;
        s->c8=0;
        s->c0=0.0f;
    }
    {
        s32 lost = (*(Hero_003304C0 *)D_001A4BE0).health < s->df;
        s->df=(u8)(*(Hero_003304C0 *)D_001A4BE0).health;
        if (!s->d6 && lost) {
            func_L07_00334C28(obj);
            s->d6=func_00382468(1000)+2000;
        }
    }
    if (!s->d8 && func_L07_003A24C8() >= 750 && func_L07_00334EC0(obj)) {
        s->d8=func_00382468(1000)+2000;
    }
    s->cc *= 0.88f;
    s->c4 *= 0.88f;
    func_0038CB00(&s->d4);
    func_0038CB00(&s->d2);
    func_0038CB00(&s->d0);
    func_0038CB00(&s->d6);
    func_0038CB00(&s->d8);
}
/* localdecomp:end func_L07_003304C0 */

/* localdecomp:start func_L07_00330748 */
extern u8 D_001A4BE0[];
extern s32 D_00142668[];
extern void func_L07_00331890(void *);
extern s32 func_L07_003338C0(s32, s32);
extern s32 func_00382468(s32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_00330748(u8 *a0, s32 a1) {
    u8 *d;
    u8 *p;

    d = *(u8 **)(a0 + 0x68);
    d[0x9F] = 0;
    d[0x9E] = a1;
    func_L07_00331890(a0);
    d[0xA8] = 4;
    d[0xAA] = func_L07_003338C0(d[0x9E], d[0x9F]);
    p = D_001A4BE0;
    *(s32 *)(p + 0x2850) = D_00142668[0];
    d[0xDE] = p[0x2850];
    d[0xDF] = p[0x2850];
    *(s32 *)(d + 0xC0) = 0;
    *(s32 *)(d + 0xC4) = 0;
    *(s32 *)(d + 0xC8) = 0;
    *(s32 *)(d + 0xCC) = 0;
    *(s16 *)(d + 0xD4) = 0;
    *(s16 *)(d + 0xD2) = 0;
    *(s16 *)(d + 0xD0) = 0;
    *(s16 *)(d + 0xD6) = 0;
    *(s16 *)(d + 0xD8) = func_00382468(0x3E8) + 0x7D0;
    if (*(s32 *)(d + 0xE0) & 1) {
        *(s32 *)(d + 0xE0) = 3;
    } else {
        *(s32 *)(d + 0xE0) = 0;
    }
    func_L01_00456230(a0, 0);
    func_L01_004450F0(a0, 2, -1);
}
/* localdecomp:end func_L07_00330748 */

/* localdecomp:start func_L07_00330828 */
typedef struct {
    u8 pad0[0x84];
    u16 f84;
    u8 pad1[0x8A - 0x86];
    u16 f8A;
    u8 pad2[0xF0 - 0x8C];
} G_00330828;

extern void func_L07_00335448(u8 *);
extern s32 func_L07_00333460(s32, s32);
extern void func_L07_00330AA0(u8 *);
extern void func_L07_00332928(u8 *);
extern s32 func_L07_00332958(u8 *);
extern void func_L07_00334968(u8 *, s32);
extern void func_L01_0044CD60(s32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L01_004450F0(void *, s32, s32);

extern G_00330828 D_L07_002C72C0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];

void func_L07_00330828(u8 *arg0) {
    s32 flag = 0;
    u8 *d = *(u8 **)(arg0 + 0x68);
    u8 *e;
    G_00330828 *gun;

    func_L07_00335448(arg0);
    e = (u8 *)func_L07_00333460(d[0x9E], -1);
    if (e == 0) {
        flag = 1;
        e = (u8 *)func_L07_00333460(d[0x9E], d[0x9F]);
        d[0x9F] = 0xFF;
        func_L07_00330AA0(arg0);
    } else {
        d[0x9F] = 0xFF;
        func_L07_00330AA0(arg0);
    }
    if (e[3] != 0) {
        flag = 1;
    } else {
        if (*(s32 *)(e + 8) != -1) {
            func_L01_0044CD60(*(s32 *)(e + 8));
            gun = &D_L07_002C72C0[D_001425C0[*(s32 *)(e + 8)]];
            if (gun->f84 != 0)
                D_001427F0[*(s32 *)(e + 8)] = gun->f8A;
        }
    }
    if (flag) {
        func_L07_00332928(arg0);
        func_L07_00334968(d + 0x80, 0x10);
        d[0xB1] = 0xFF;
        func_L07_00332958(arg0);
        func_L07_00332958(arg0);
    }
    func_003A52A0(0, 4, arg0);
    func_003A52A0(1, 4, arg0);
    func_003A52A0(2, 4, arg0);
    func_L01_004450F0(arg0, 4, -1);
}
/* localdecomp:end func_L07_00330828 */

/* localdecomp:start func_L07_003309A0 */
extern u8 *D_L07_001DF500;
extern s32 D_001A5E08[];
extern s32 func_L07_00333460(s32, s32);
extern s32 func_L07_003349E8(s32);
extern void func_L07_00334A20(s32);
extern void func_L07_00334FB0(u8 *);
extern void func_L07_003350F0(u8 *);
extern void func_L07_00330828(u8 *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00479280(void);
extern s32 func_L01_0047B420(void);
extern void func_L01_0047B990(void);
extern void func_L02_003C5DC0(s32);
extern void func_L01_003EC9E0(s32);

void func_L07_003309A0(u8 *arg0) {
    u8 *d = *(u8 **)(arg0 + 0x68);
    u8 *base;
    s32 *p;

    base = D_L07_001DF500 + (*(s32 *)(d + 0xA0) << 7);
    func_L01_004F50C8(base + 0x30, base + 0x70, 0x74, 1);
    p = (s32 *)func_L07_00333460(d[0x9E], d[0x9F]);
    if (p[2] != -1 && D_001A5E08[0] != p[2]) {
        func_L01_0044CD60(9);
    }
    if (d[0xAA] != 0 || func_L07_003349E8(d[0x9E]) != 0) {
        func_L07_00334FB0(arg0);
        func_L01_004450F0(arg0, 3, -1);
    } else {
        func_L07_003350F0(arg0);
        func_L01_00479280();
        func_L01_0047B420();
        func_L01_0047B990();
        func_L07_00334A20(d[0x9E]);
        func_L07_00330828(arg0);
        func_L02_003C5DC0(*(s32 *)(d + 0x74));
        func_L01_003EC9E0(*(s32 *)(d + 0x74));
    }
}
/* localdecomp:end func_L07_003309A0 */

/* localdecomp:start func_L07_00330AA0 */
extern u8 D_001427C3[];
extern u8 D_00142CB6[];
__asm__(".extern D_L07_001DCE78, 4");
extern s32 D_L07_001DCE78;
void func_L07_00330AA0(u8 *moby) {
    extern s32 func_L01_005170B8(s32, u32);
    extern s32 func_L07_00333460(s32, s32);
    extern void func_L01_00451F60(s32, s32, s32);
    extern s32 func_L01_00517190(s32, s32);
    extern void func_L01_004C94B0(void);
    extern void func_003E4D10(s32, s32);
    extern void func_L07_00332848(u8 *);
    extern void func_L07_003328D0(s32);
    extern void func_L07_003A2380(s32, u8 *, s32, s32);
    extern s32 func_00382468(s32);
    extern void func_L03_003AF098(s32);
    extern void func_L07_003318D8(u8 *);
    extern s32 func_L07_003338C0(s32, s32);
    extern void func_L07_00332230(u8 *, s32);
    extern void func_L01_0045F1E8(s32, s32);
    extern void func_L07_003354A0(u8 *);
    u8 *s = *(u8 **)(moby + 0x68);
    u8 *prev;
    u8 *cur;
    s32 count;
    s32 i;
    s16 *dst;
    u16 *src;
    if (D_L07_002B0D40[s[0x9E]].pad1[4] || s[0x9F] == 255) {
        s[0xBE] = 0;
        i = 0;
        dst = (s16 *)(s + 0x90);
        for (; i < 8; i++) func_L01_005170B8(0x150008 + i, 0x8066CCFF);
        count = 0;
        *(s32 *)(s + 0xB8) = 0;
        prev = 0;
        if (s[0x9F] != 255) prev = (u8 *)func_L07_00333460(s[0x9E], s[0x9F]);
        s[0x9F]++;
        cur = (u8 *)func_L07_00333460(s[0x9E], s[0x9F]);
        *(s16 *)(s + 0xA4) = -1;
        if (*(s32 *)(cur + 4) != -1) *(s16 *)(s + 0xA4) = (*(s32 *)(cur + 4) * 5 + 2) / 6;
        if (*(s16 *)(s + 0xA4) != -1) {
            func_L01_00451F60(0x125E, -1, 0);
            count = 1;
            func_L01_00517190(0x150008, 0xEC5A);
            s[0xBE] |= 1;
        }
        if (cur[0] == 0) {
            if (D_001427F0[22]) {
                D_001427C3[0] = ((u8 *)D_001427F0)[0x58] + 1;
                D_001427F0[22] = 0;
            }
            func_L01_004C94B0();
            func_L01_00517190(0x150008 + count, 0xEC56);
            if (prev == 0 || prev[0] != 0) s[0xBE] |= 1 << count;
            count++;
        }
        if (*(s32 *)(cur + 8) != -1) {
            if (D_00142CB6[0]) {
                if (D_001427F0[22]) {
                    D_001427C3[0] = ((u8 *)D_001427F0)[0x58] + 1;
                    D_001427F0[22] = 0;
                }
                func_L01_004C94B0();
            }
            func_L01_00517190(0x150008 + count, 0xEC58);
            if (prev == 0 || *(s32 *)(prev + 8) != *(s32 *)(cur + 8)) s[0xBE] |= 1 << count;
            count++;
        }
        if (cur[2]) {
            func_L01_00517190(0x150008 + count, 0xEC57);
            if (prev == 0 || prev[2] == 0) {
                s[0xAB] = 0;
                *(s32 *)(s + 0xAC) = 0;
                func_L01_00451F60(0x125F, -1, 0);
                s[0xBE] |= 1 << count;
            }
            count++;
        }
        if (prev != 0 && prev[2] != 0 && cur[2] == 0) {
            s32 old = s[0xDC];
            s32 n = s[0xAB];
            s[0xDD] = 3;
            s[0xDC] = old + n;
            func_003E4D10(30, n);
        }
        if (cur[3]) {
            if (prev == 0 || prev[3] == 0) {
                {
                    u8 *g = D_001A4BE0;
                    if (*(s32 *)(g + 0x234) >= 3) *(s32 *)(g + 0x234) = 2;
                }
                func_L07_00332848(moby);
                func_L01_00451F60(0x1260, -1, 0);
            }
        } else func_L07_003328D0((s32)moby);
        if (s[0xBE]) *(s16 *)(s + 0xBC) = 200;
        if (s[0x9F]) {
            if (s[0xBE]) func_L07_003A2380(59, moby, 0, 100);
            else if (func_00382468(15) == 0) func_L07_003A2380(42, moby, 0, 100);
        }
        func_L03_003AF098(count);
    } else {
        s[0x9F]++;
        if (func_00382468(15) == 0) func_L07_003A2380(42, moby, 0, 100);
    }
    dst = (s16 *)(s + 0x90);
    func_L07_003318D8(moby);
    s[0xAA] = func_L07_003338C0(s[0x9E], s[0x9F]);
    if (s[0xAA]) {
        {
                    u8 *g = D_001A4BE0;
                    if (*(s32 *)(g + 0x234) >= 3) *(s32 *)(g + 0x234) = 2;
                }
        func_L07_00332230(moby, 1);
        func_L01_0045F1E8(*(s32 *)(s + 0xE8), -1);
    } else func_L01_0045F1E8(*(s32 *)(s + 0xE4), -1);
    {
        s32 j;
        for (j = 0; j < 7; j++) dst[j] = ((u16 *)&D_L07_001DCE78)[j * 2];
    }
    func_L07_003354A0(moby);
}
/* localdecomp:end func_L07_00330AA0 */

/* localdecomp:start func_L07_00330F30 */
extern u8 D_001426E0[];
extern u8 D_001A74A9[];
extern s32 D_00142848[];
extern void func_L01_003F1760(void);
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_00330F30(u8 *arg0) {
    D_001A74A9[0] = 0;
    if (D_001426E0[0xE3] != 0) {
        D_00142848[0] = D_001426E0[0xE3] - 1;
        D_001426E0[0xE3] = 0;
    }
    func_L01_003F1760();
    func_L01_004450F0(arg0, 8, -1);
}
/* localdecomp:end func_L07_00330F30 */

/* localdecomp:start func_L07_00330F98 */
extern void func_L07_003328D0(s32);
extern void func_L01_004AA760(s32, s32);
extern void func_L01_004596E8(s32, void (*)(void));
extern void func_L07_003332B8(void);
extern s32 D_L07_001D7B20;

void func_L07_00330F98(s32 arg0) {
    void (*deflt)(void);

    func_L07_003328D0(arg0);
    func_L01_004AA760(0, arg0);
    func_L01_004AA760(1, arg0);
    func_L01_004AA760(2, arg0);
    deflt = func_L07_003332B8;
    D_L07_001D7B20 = -1;
    func_L01_004596E8(0, deflt);
    func_L07_00331890(arg0);
}
/* localdecomp:end func_L07_00330F98 */

/* localdecomp:start func_L07_00331008 */
typedef struct {
    u8 p00[0x1C];
    u8 f1C;
    u8 f1D;
} S_00331008;

typedef struct {
    s16 arr[1];
} T_00331008;

extern s32 *func_L07_00333918(void *);
extern void func_L07_003310E8(u8 *, void *);
extern s32 D_001A71A4[];

s32 func_L07_00331008(u8 *arg0, void *arg1) {
    S_00331008 *r;
    T_00331008 *q;
    s32 base;
    s16 v;

    base = *(s32 *)(arg0 + 0x68);
    r = (S_00331008 *)func_L07_00333918(arg1);
    if (r->f1C == 3) {
        return 1;
    }
    if (D_001A71A4[0] == 0x74) {
        if (r->f1C == 1) {
            func_L07_003310E8(arg0, arg1);
        }
        return 0;
    }
    if (r->f1C == 1) {
        return 1;
    }
    q = (T_00331008 *)(base + 0x90);
    v = q->arr[r->f1D];
    if (v == -1) {
        r->f1C = 1;
        return 1;
    }
    if (v > 0) {
        r->f1C = 1;
        q->arr[r->f1D] -= 1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L07_00331008 */

/* localdecomp:start func_L07_003310E8 */
extern s32 *func_L07_00333918(void *);

void func_L07_003310E8(u8 *arg0, void *arg1) {
    s32 *r = func_L07_00333918(arg1);

    if (*(u8 *)((u8 *)r + 0x1C) == 1) {
        s16 *q = (s16 *)(*(s32 *)(arg0 + 0x68) + 0x90);
        s16 *p = q + *(u8 *)((u8 *)r + 0x1D);

        if (*p != -1) {
            *p += 1;
        }
    }
    *(u8 *)((u8 *)r + 0x1C) = 0;
}
/* localdecomp:end func_L07_003310E8 */

/* localdecomp:start func_L07_00331158 */
extern s32 *func_L07_00333918(void *);
extern void func_L07_003310E8(u8 *, void *);
extern u8 *func_L01_00449020(u8 *);
extern u8 *func_00382348(u8 *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L07_00333310(void *, u8 *, u8 *, s32, u8);

void func_L07_00331158(u8 *arg0) {
    u8 *b;
    u8 *c;
    u8 *r;

    b = func_L01_00449020(arg0);
    c = func_00382348(arg0);
    r = (u8 *)func_L07_00333918(arg0);
    func_L01_00452860(arg0, c, 0);
    if (arg0[0x20] < 5) {
        if (r[0x1C] == 1) {
            func_L07_003310E8(*(u8 **)r, arg0);
        }
        r[0x1C] = 0;
        *(s16 *)(b + 0x14) = 0;
    } else {
        if (c[0x2F] != 0) {
            u8 flag = 0;

            if (r[0x1C] == 1) {
                flag = 1;
                func_L07_003310E8(*(u8 **)r, arg0);
            }
            r[0x1C] = 3;
            func_L01_00456BD0(arg0, 5);
            func_L07_00333310(arg0, b, r, 3, flag);
        } else {
            if (r[0x1C] != 1) {
                r[0x1C] = 2;
            }
            func_L01_00456BD0(arg0, 3);
            func_L07_00333310(arg0, b, r, 1, 0);
        }
    }
}
/* localdecomp:end func_L07_00331158 */

/* localdecomp:start func_L07_00331288 */
extern void func_L07_003312E8(s32, s32);

void func_L07_00331288(s32 a0)
{
    s32 i;

    for (i = 0; i < 6; i++) {
        if (i < 3 || i > 4) {
            func_L07_003312E8(a0, i);
        }
    }
}
/* localdecomp:end func_L07_00331288 */

/* localdecomp:start func_L07_003312E8 */
typedef struct { u8 pad[0x1C]; s32 groups[7]; u8 gap[0x58]; s16 limits[7]; } V_3312E8;
extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458;
extern u8 *D_L07_001DF41C_003312E8;
extern u8 D_001A4C60_003312E8[];
extern s32 *func_L07_00333918(void *);
extern void func_L07_003310E8(u8 *, void *);
extern s32 func_L07_00331008(u8 *, void *);
extern f32 func_0038CF38(void *, void *);
void func_L07_003312E8(s32 self, s32 group) {
    V_3312E8 *v = *(V_3312E8 **)((u8 *)self + 0x68);
    s32 available = 0;
    s32 reclaim = 1;
    u8 *farthest = 0, *nearest = 0;
    f32 farDist = -1.0f, nearDist = 10000000.0f;
    u16 *p;
    if (v->limits[group] != -1) available = reclaim;
    if (v->limits[group] > 0) reclaim = 0;
    for (p = D_L07_0021C020[v->groups[group]];
         (v->groups[group] & 255) != 255 && v->groups[group] <= D_L07_001DF458 && p;
         p++) {
        u8 *obj;
        u8 *r;
        f32 distance;
        if (((s16 *)p)[-1] < 0 && p != D_L07_0021C020[v->groups[group]]) break;
        obj = D_L07_001DF41C_003312E8 + ((*p & 0x7FFF) << 8);
        if (!obj) break;
        r = (u8 *)func_L07_00333918(obj);
        if (obj[0x20] >= 6 && r[0x1D] == group && available) {
            s32 state = r[0x1C];
            if (state == 3) continue;
            distance = func_0038CF38(obj + 0x10, D_001A4C60_003312E8);
            if (distance < nearDist) { nearest = obj; nearDist = distance; }
            if (reclaim && r[0x1C] == 1 && distance > farDist) {
                farthest = obj; farDist = distance;
            }
        }
    }
    if (nearest && ((u8 *)func_L07_00333918(nearest))[0x1C] != 1) {
        if (farthest) func_L07_003310E8((u8 *)self, farthest);
        func_L07_00331008((u8 *)self, nearest);
    }
}
/* localdecomp:end func_L07_003312E8 */
