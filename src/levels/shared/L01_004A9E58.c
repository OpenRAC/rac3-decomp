#include "common.h"

/* localdecomp:start func_L01_004A9E58 */
#include "vu0.h"
typedef struct {
    u8 pad00[0x10];
    vu0_v4 v10;
    u8 f20;
    u8 pad21[0x9F];
    u8 mC0[0x40];
} Obj_004A9E58;
typedef struct {
    u8 pad00[0x18];
    u8 f18;
    u8 f19;
    s16 f1A;
    s32 f1C;
} Info_004A9E58;
typedef struct {
    u32 handle;
    Info_004A9E58 *info;
    u8 pad08[4];
    s16 vol;
    u8 pad0E[2];
    u8 state;
    u8 pad11[2];
    u8 f13;
    s32 f14;
    s32 f18;
    Obj_004A9E58 *obj;
    vu0_v4 pos;
    vu0_v4 v30;
    s32 f40;
    u8 pad44[8];
    s32 f4C;
    u8 pad50[8];
    u32 flags;
    u8 pad5C[0x24];
} Ent_004A9E58;
typedef struct {
    s32 vol[6];
    u8 pad18[0x28];
    u8 f40;
    u8 f41;
    u8 f42;
    u8 f43;
    s32 f44;
    u8 pad48[0x48];
    s32 f90[9];
    s32 fB4;
    u8 padB8[8];
    Ent_004A9E58 ent[52];
    u8 pad1AC0[0x60];
    s32 f1B20;
} S_004A9E58;
extern u8 D_001A30B0[];
extern s32 D_L01_001D6698;
__asm__(".extern D_L01_001D6698, 16");
extern s32 D_L01_001E2E90[];
extern u8 D_L01_001E2A40[];
extern s32 D_L01_001D52E4;
__asm__(".extern D_L01_001D52E4, 16");
extern s32 D_L01_001D6694;
extern s32 func_0013B620(void);
extern void func_003A3FE0(void);
extern void func_0013CF80(s32, s32, s32, s32, s32);
extern void func_0013CFF8(s32, s32, s32, s32);
extern void func_0013BF30(s32, s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_003A3DC8(void *, void *, void *, void *);
extern s32 func_003A3E28(void *, void *);
extern void func_0013C118(s32);
extern void func_0013C200(s32, void *, void *);
extern void func_0013C2C0(s32, s32, s32, s32, s32, s32, void *, void *);
extern void func_0013C0B8(s32, s32, s32, s32, s32, s32, void *, void *);
extern void func_003A5550(s32, long);
extern void func_003A5508(s32, long);
extern void func_003A1F30(void);
extern void func_0013CA28(void);
extern void func_0013CA20(void);

static __inline__ void track_004A9E58(vu0_v4 *vel, vu0_v4 *cur, vu0_v4 *prev) {
    vec_sub_ab(vel, cur, prev);
    *prev = *cur;
}

s32 func_L01_004A9E58(void) {
    s32 *arr[4];
    vu0_v4 delta;
    f32 zero;
    s32 n;
    s32 dim;
    s32 i;
    s32 ja, jb, jc, jd, je;
    u8 *p;
    u32 *fl;

    n = D_L01_001D6698 + 1;
    dim = D_L01_001E2E90[0];
    func_0013B620();
    zero = 0.0f;
    func_003A3FE0();
    if (((S_004A9E58 *)D_001A30B0)->f43 & 8) {
        func_0013CF80(2, 0, 0, 0, 0);
    } else if (((S_004A9E58 *)D_001A30B0)->f43 & 0x13) {
        func_0013CF80(2, ((S_004A9E58 *)D_001A30B0)->f40, ((S_004A9E58 *)D_001A30B0)->fB4, ((S_004A9E58 *)D_001A30B0)->f41, ((S_004A9E58 *)D_001A30B0)->f42);
    } else if (((S_004A9E58 *)D_001A30B0)->f43 & 4) {
        func_0013CFF8(2, ((S_004A9E58 *)D_001A30B0)->fB4, 0xC, 3);
    }
    ((S_004A9E58 *)D_001A30B0)->f43 = 0;
    if (((S_004A9E58 *)D_001A30B0)->f1B20 & 2) {
        s32 v = ((S_004A9E58 *)D_001A30B0)->vol[1];
        if (dim) {
            v = v * 3 / 5;
        }
        ((S_004A9E58 *)D_001A30B0)->vol[1] = v;
        func_0013BF30(1, v);
    }
    if (((S_004A9E58 *)D_001A30B0)->f1B20 & 1) {
        func_0013BF30(0, ((S_004A9E58 *)D_001A30B0)->vol[0]);
    }
    if (((S_004A9E58 *)D_001A30B0)->f1B20 & 8) {
        func_0013BF30(3, ((S_004A9E58 *)D_001A30B0)->vol[3]);
    }
    if (((S_004A9E58 *)D_001A30B0)->f1B20 & 0x10) {
        func_0013BF30(4, ((S_004A9E58 *)D_001A30B0)->vol[4]);
    }
    if (((S_004A9E58 *)D_001A30B0)->f1B20 & 4) {
        func_0013BF30(2, ((S_004A9E58 *)D_001A30B0)->vol[2]);
        func_0013BF30(6, ((S_004A9E58 *)D_001A30B0)->vol[2]);
    }
    if (((S_004A9E58 *)D_001A30B0)->f1B20 & 0x20) {
        func_0013BF30(5, ((S_004A9E58 *)D_001A30B0)->vol[5]);
    }

    fl = (u32 *)0x70000000;
    p = (u8 *)0x70000000 + 0xD0;
    for (ja = 0; ja < n; ja++) {
        arr[ja] = (s32 *)p;
        p += 0xD0;
    }
    func_0038CB78((void *)0x70000000, 0, p - (u8 *)0x70000000);

    for (i = 0; i < 52; i++) {
        Obj_004A9E58 *obj;
        s32 dead;
        s32 mode;

        if (((S_004A9E58 *)D_001A30B0)->ent[i].state != 7) {
            if (((S_004A9E58 *)D_001A30B0)->ent[i].handle == 0) {
                continue;
            }
            if (((S_004A9E58 *)D_001A30B0)->ent[i].handle == 0xFFFFFFFF) {
                continue;
            }
        }
        obj = ((S_004A9E58 *)D_001A30B0)->ent[i].obj;
        dead = 0;
        if (obj != 0) {
            u8 st = obj->f20;
            if (st == 0xFE) {
                goto is_dead;
            }
            if (st == 0xFD) {
            is_dead:
                dead = 1;
            }
        }
        if (dead) {
            ((S_004A9E58 *)D_001A30B0)->ent[i].obj = 0;
        }
        if (((S_004A9E58 *)D_001A30B0)->ent[i].state == 4 || (((S_004A9E58 *)D_001A30B0)->ent[i].state != 6 && dead && ((S_004A9E58 *)D_001A30B0)->ent[i].info->f18 != 0)) {
            fl[i] = 0x20;
            continue;
        }
        mode = D_L01_001D6694;
        if (mode != 0 && mode != 2 && mode != 6 && ((S_004A9E58 *)D_001A30B0)->ent[i].state != 7) {
            fl[i] = 0x10;
            continue;
        }
        {
            if (((S_004A9E58 *)D_001A30B0)->ent[i].obj != 0 && !(((S_004A9E58 *)D_001A30B0)->ent[i].flags & 8)) {
                if (((S_004A9E58 *)D_001A30B0)->ent[i].flags & 0x40) {
                    vu0_v4 tmp;
                    func_0038D000(&tmp, &((S_004A9E58 *)D_001A30B0)->ent[i].v30, obj->mC0);
                    vec_add_ba(&tmp, &tmp, &obj->v10);
                    track_004A9E58(&delta, &tmp, &((S_004A9E58 *)D_001A30B0)->ent[i].pos);
                } else {
                    ((S_004A9E58 *)D_001A30B0)->ent[i].pos.z -= 1.0f;
                    track_004A9E58(&delta, &((S_004A9E58 *)D_001A30B0)->ent[i].obj->v10, &((S_004A9E58 *)D_001A30B0)->ent[i].pos);
                    ((S_004A9E58 *)D_001A30B0)->ent[i].pos.z += 1.0f;
                }
            } else {
                qzero(&delta);
            }
        }
        {
            s32 share[4];
            if (!(((S_004A9E58 *)D_001A30B0)->ent[i].flags & 0x10)) {
                for (jb = 0; jb < n; jb++) {
                    share[jb] = func_003A3DC8(&((S_004A9E58 *)D_001A30B0)->ent[i], &((S_004A9E58 *)D_001A30B0)->ent[i].pos, D_L01_001E2A40 + jb * 0x460, (void *)1);
                    arr[jb][i] = share[jb] * ((S_004A9E58 *)D_001A30B0)->ent[i].vol / 1024;
                }
                if (!(((S_004A9E58 *)D_001A30B0)->ent[i].info->f19 & 2)) {
                    fl[i] |= 8;
                }
            } else {
                for (jc = 0; jc < n; jc++) {
                    share[jc] = 0x400;
                    arr[jc][i] = ((S_004A9E58 *)D_001A30B0)->ent[i].vol;
                }
            }
            if (dim && !(((S_004A9E58 *)D_001A30B0)->ent[i].info->f19 & 4) && zero < ((S_004A9E58 *)D_001A30B0)->ent[i].pos.z) {
                for (jd = 0; jd < n; jd++) {
                    arr[jd][i] /= 2;
                }
            }
            fl[i] |= 1;
            {
                s32 s1 = 0;
                s32 s2 = 0;
                for (je = 0; je < n; je++) {
                    s1 += share[je];
                    s2 += arr[je][i];
                }
                s1 = s1 < 0x400 - D_L01_001D52E4 ? s1 : 0x400 - D_L01_001D52E4;
                s2 = s2 < 0x400 - D_L01_001D52E4 ? s2 : 0x400 - D_L01_001D52E4;
                if (s1 < 0x20 && s2 < 0x20 && (((S_004A9E58 *)D_001A30B0)->ent[i].flags & 4)) {
                    fl[i] = 0x20;
                }
            }
        }
    }

    for (i = 0; i < 52; i++) {
        u32 f;
        u32 h;
        if (fl[i] == 0) {
            continue;
        }
        h = ((S_004A9E58 *)D_001A30B0)->ent[i].handle;
        ((S_004A9E58 *)D_001A30B0)->ent[i].handle = 0xFFFFFFFF;
        f = fl[i];
        if (f & 0x20) {
            if (((S_004A9E58 *)D_001A30B0)->ent[i].state == 7) {
                ((S_004A9E58 *)D_001A30B0)->ent[i].obj = 0;
                ((S_004A9E58 *)D_001A30B0)->ent[i].f40 = 0;
                ((S_004A9E58 *)D_001A30B0)->ent[i].state = 0;
                continue;
            }
            func_0013C118(h);
            ((S_004A9E58 *)D_001A30B0)->ent[i].state = 6;
            func_0013C200(h, func_003A5550, &((S_004A9E58 *)D_001A30B0)->ent[i]);
            ((S_004A9E58 *)D_001A30B0)->ent[i].f4C = ((S_004A9E58 *)D_001A30B0)->ent[i].f13;
        } else if (f & 0x10) {
            func_0013C200(h, func_003A5550, &((S_004A9E58 *)D_001A30B0)->ent[i]);
            ((S_004A9E58 *)D_001A30B0)->ent[i].f4C = ((S_004A9E58 *)D_001A30B0)->ent[i].f13;
        } else {
            s32 f14 = ((S_004A9E58 *)D_001A30B0)->ent[i].f14;
            s32 mode = f14 ? 0x11 : 1;
            s32 f18 = ((S_004A9E58 *)D_001A30B0)->ent[i].f18;
            s32 pan = 0;
            s32 aux = 0;
            s32 sum;
            s32 k;
            Info_004A9E58 *info;
            if (f18) {
                aux = f18;
                mode |= 8;
            }
            if (f & 2) {
                mode |= 6;
                pan = func_003A3E28(&((S_004A9E58 *)D_001A30B0)->ent[i], &((S_004A9E58 *)D_001A30B0)->ent[i].pos);
            }
            sum = 0;
            for (k = 0; k < n; k++) {
                sum += arr[k][i];
            }
            sum = sum < 0x400 - D_L01_001D52E4 ? sum : 0x400 - D_L01_001D52E4;
            if (((S_004A9E58 *)D_001A30B0)->ent[i].state != 7) {
                func_0013C2C0(h, mode, sum, pan, aux, f14, func_003A5550, &((S_004A9E58 *)D_001A30B0)->ent[i]);
                ((S_004A9E58 *)D_001A30B0)->ent[i].f4C = ((S_004A9E58 *)D_001A30B0)->ent[i].f13;
            } else {
                info = ((S_004A9E58 *)D_001A30B0)->ent[i].info;
                if (info == 0 || ((S_004A9E58 *)D_001A30B0)->f90[info->f1C] == -1 || ((S_004A9E58 *)D_001A30B0)->f90[info->f1C] == 0) {
                    ((S_004A9E58 *)D_001A30B0)->ent[i].obj = 0;
                    ((S_004A9E58 *)D_001A30B0)->ent[i].f40 = 0;
                    ((S_004A9E58 *)D_001A30B0)->ent[i].state = 0;
                } else {
                    ((S_004A9E58 *)D_001A30B0)->ent[i].state = 1;
                    func_0013C0B8(((S_004A9E58 *)D_001A30B0)->f90[info->f1C], info->f1A, sum, pan, aux, f14, func_003A5508, &((S_004A9E58 *)D_001A30B0)->ent[i]);
                }
            }
        }
    }
    func_003A1F30();
    func_0013CA28();
    func_0013B620();
    func_0013CA20();
    ((S_004A9E58 *)D_001A30B0)->f44 = 0;
    return 0;
}
/* localdecomp:end func_L01_004A9E58 */

/* localdecomp:start func_L01_004AA710 */
extern u8 D_001A30B0[];

int func_L01_004AA710(int a0, int a1)
{
    if (a1 >= 0) {
        u8 *p = D_001A30B0 + a1 * 128;
        if (*(int *)(p + 220) == a0) {
            u8 b = p[208];
            if ((u32)(b - 1) < 2 || b == 7) {
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L01_004AA710 */

/* localdecomp:start func_L01_004AA760 */
typedef struct {
    u8 pad0[10];
    s16 f10;
    u8 pad12[16];
    s32 f28;
    u8 pad32[96];
} Ent_004A6D70;

extern Ent_004A6D70 D_001A3170[];
extern void func_003A4F28(s32);

void func_L01_004AA760(s32 arg0, s32 arg1)
{
    Ent_004A6D70 *p;
    s32 i;

    p = D_001A3170;
    for (i = 0; i < 52; i++, p++) {
        if ((arg1 == 0 || arg1 == p->f28) && arg0 == p->f10) {
            func_003A4F28(i);
        }
    }
}
/* localdecomp:end func_L01_004AA760 */

/* localdecomp:start func_L01_004AA7E8 */
extern Ent_004A6D70 D_001A3170[];
typedef struct {
    u8 pad0[28];
    u8 *owner;
    u8 pad20[56];
    s32 flags;
    u8 pad5C[36];
} Entry_004A6DF8;

extern void func_003A4F28(s32);

void func_L01_004AA7E8(u8 *obj, s32 check)
{
    s32 i;
    Entry_004A6DF8 *e;

    if (obj == 0) {
        return;
    }
    e = ((Entry_004A6DF8 *)&D_001A3170);
    for (i = 0; i < 52; i++, e++) {
        if (obj == e->owner) {
            if (check == 0 || (e->flags & 4)) {
                func_003A4F28(i);
            }
        }
    }
    obj[109] = 255;
}
/* localdecomp:end func_L01_004AA7E8 */
