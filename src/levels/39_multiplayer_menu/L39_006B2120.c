#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_006B2120 */
typedef struct O_006B2120 O_006B2120;
typedef struct {
    u8 pad0[0x78];
    s32 (*f78)(O_006B2120 *);
    u8 pad7C[0x88 - 0x7C];
    void (*f88)(O_006B2120 *, s32);
    s32 (*f8C)(O_006B2120 *);
} V_006B2120;
struct O_006B2120 {
    u8 pad0[0x60];
    V_006B2120 *vt;
};
typedef struct {
    u8 pad0[0x110];
    O_006B2120 *f110[(0x290 - 0x110) / 4];
    s32 f290;
    u8 pad294[0x2B0 - 0x294];
    s32 f2B0;
    u8 pad2B4[0x494 - 0x2B4];
    s32 f494;
} S_006B2120;
void func_L39_0068B2F8();

s32 func_L39_006B2120(S_006B2120 *this, s32 arg1) {
    if (arg1 == 3 || arg1 == 4) {
        if (this->f290 == 10) {
            func_L39_0068B2F8(this, this->f2B0, 0);
            return 1;
        }
        if (this->f494 > 0) {
            func_L39_0068B2F8(this, 10, 0);
            return 1;
        }
    }
    if (arg1 == 1 && this->f290 == 0) {
        func_L39_0068B2F8(this, 6, 0);
        return 1;
    }
    if (arg1 == 2 && this->f290 == 6) {
        func_L39_0068B2F8(this, 0, 0);
        return 1;
    }
    if (this->f290 == 10) {
        if (arg1 == 1 && this->f110[this->f290]->vt->f8C(this->f110[this->f290]) == 0) {
            this->f110[this->f290]->vt->f88(this->f110[this->f290], this->f494 - 1);
            return 1;
        }
        if (arg1 == 2 && this->f110[this->f290]->vt->f8C(this->f110[this->f290]) ==
                             this->f110[this->f290]->vt->f78(this->f110[this->f290]) - 1) {
            this->f110[this->f290]->vt->f88(this->f110[this->f290], 0);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006B2120 */

/* localdecomp:start func_L39_006B22B0 */
typedef struct {
    u8 pad0[0x199];
    u8 f199;
} P_006B22B0;
typedef struct {
    u8 pad0[0x4C];
    P_006B22B0 *f4C;
} G_006B22B0;

__asm__(".extern D_L39_0024D760_006B22B0, 16");
extern G_006B22B0 *D_L39_0024D760_006B22B0;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_00195410(void);
void func_L39_006DC148(s32, s32);
s32 func_L39_006DAFC8(P_006B22B0 *);
s32 func_L39_006DB948(P_006B22B0 *, s32, s32, s32, s32);
void func_L04_00523E58(P_006B22B0 *);

s32 func_L39_006B22B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 ok = 1;
    P_006B22B0 *p = D_L39_0024D760_006B22B0->f4C;
    s32 i;

    {
        s32 start = (s32)func_00130760(func_0012DCB0(), 0x24000);
        while (p->f199 != 0) {
            func_00195410();
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start > 15000) {
                ok = 0;
                break;
            }
        }
    }
    if (ok) {
        ok = ((s32 (*)(P_006B22B0 *, s32))func_L39_006DC148)(p, arg3);
    }
    for (i = 2; i != 0; i--) {
        if (ok) {
            ok = func_L39_006DAFC8(p);
            if (ok) {
                s32 start = (s32)func_00130760(func_0012DCB0(), 0x24000);
                while (p->f199 != 0) {
                    func_00195410();
                    if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start > 15000) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    ok = func_L39_006DB948(p, arg3, arg2, -1, 0);
                    if (ok) {
                        break;
                    }
                }
            }
        }
    }
    func_L04_00523E58(p);
    return ok;
}
/* localdecomp:end func_L39_006B22B0 */

/* localdecomp:start func_L39_006B2450 */
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
extern char *D_001DC204_sda;
void func_L39_006BD408(s32);

s32 func_L39_006B2450(s32 arg0, s32 arg1, s32 arg2) {
    func_L39_006BD408(D_L39_00247914[0xE0 / 4]);
    if (arg2 != 0) {
        *(s32 *)(D_001DC204_sda + 0x284) = 0x1F;
    }
    return 1;
}
/* localdecomp:end func_L39_006B2450 */

/* localdecomp:start func_L39_006B2498 */
typedef struct {
    u8 pad0[0x2A8];
    s32 time;
    s32 state;
    s32 connection;
    s32 mode;
    u8 query[0x1E0];
} UI_006B2498;

typedef struct {
    u8 pad0[0x1C];
    s32 id;
    u16 min;
    u8 pad22[2];
    u16 max;
    u8 pad26[6];
    s32 version;
    u8 pad30[0x10];
    s32 flags;
    s32 type;
    s32 mode;
} E_006B2498;

typedef struct {
    s32 unused;
    s32 count;
    E_006B2498 **entries;
} Group_006B2498;

typedef struct {
    u8 pad0[0x18];
    s32 selected;
    u8 busy;
    u8 pad1D[0xF];
    Group_006B2498 groups[1];
} Browser_006B2498;

typedef struct {
    u8 pad0[0x70];
    Browser_006B2498 *browser;
} Hub_006B2498;

typedef struct {
    u8 pad0[0xC];
    s32 clients;
    u8 pad10[0x78];
    f32 first[4];
    f32 second[4];
} Game_006B2498;

extern Hub_006B2498 *D_L39_0024D760;
__asm__(".extern D_L39_0024D760, 16");
extern Game_006B2498 D_001A5CD0;
extern u8 D_L39_00248EA0[];
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
extern char *D_001DC204_sda;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);

s32 func_L39_006B2498(UI_006B2498 *ui) {
    extern char *func_00381FF0(s32);
    extern s32 func_L39_00687800(void *, char *, char **, s32, s32);
    extern void func_L39_006CC188(void *);
    extern void func_L39_006CC8F0(void *, s32, s32, s32);
    extern s32 func_L39_006DF598(f32, f32);
    extern s32 func_L39_006CC930(void *);
    extern s32 func_L39_006D5AB8(Browser_006B2498 *);
    extern void *func_L39_006CC120(void *);
    extern void func_L39_006CC158(void *, s32);
    extern s32 func_L39_006CCA88(void *, E_006B2498 *, s32);
    extern s32 func_L39_006CC238(s32, s32);
    extern void func_L39_006CC648(void *, E_006B2498 *);
    extern s32 func_L39_006CC350(void *, s32);
    extern s32 func_L39_006872E8(void *, char *, u8 *, s32, s32, f32);
    Browser_006B2498 *browser = D_L39_0024D760->browser;

    if (ui->state == 1) {
        if (browser->busy == 0) {
            char *choices[4] = { func_00381FF0(0xFBF), func_00381FF0(0x1024), func_00381FF0(0x10E2), func_00381FF0(0x1026) };
            char *menu = D_001DC204_sda;
            char *title = func_00381FF0(0xFEA);
            s32 choice = func_L39_00687800(menu, title, choices, 4, 0);

            if (choice < 0) {
                ui->state = 0;
                return 1;
            }
            ui->mode = 3;
            func_L39_006CC188(ui->query);
            func_L39_006CC8F0(ui->query, 12, 2, 0);
            if (choice == 1) {
                func_L39_006CC8F0(ui->query, 17, 2, 0);
                ui->mode = 0;
            } else if (choice == 2) {
                func_L39_006CC8F0(ui->query, 17, 2, 1);
                ui->mode = 2;
            } else if (choice == 3) {
                func_L39_006CC8F0(ui->query, 17, 2, 2);
                ui->mode = 1;
            }
            func_L39_006CC8F0(ui->query, 3, 0, func_L39_006DF598(D_001A5CD0.first[ui->mode], D_001A5CD0.second[ui->mode]) + 2);
            func_L39_006CC930(ui->query);
            func_L39_006D5AB8(browser);
            ui->time = (s32)func_00130760(func_0012DCB0(), 0x24000);
            ui->state = 2;
        } else {
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - ui->time > 15000) {
                ui->state = 0;
            }
        }
        if (ui->state == 0) {
            u8 query[0x1E0];

            func_L39_006CC120(query);
            func_L39_006CC930(query);
            func_L39_006CC158(query, 2);
        }
    }
    if (ui->state == 2) {
        if (browser->busy == 0) {
            Group_006B2498 *group = 0;

            if (browser->selected >= 0) {
                group = &browser->groups[browser->selected];
            }
            if (group) {
                s32 best = -1;
                s32 i = 0;
                E_006B2498 *selected = 0;
                s32 skill;

                ui->state = 0;
                skill = func_L39_006DF598(D_001A5CD0.first[ui->mode], D_001A5CD0.second[ui->mode]);
                for (; i < group->count; i++) {
                    E_006B2498 *entry = group->entries[i];
                    s32 id = entry->id;
                    s32 flags = entry->flags;
                    u16 min = entry->min;
                    u16 max = entry->max;
                    s32 type = entry->type;

                    if (id >= 0 && flags == 0 && max >= min + D_001A5CD0.clients && type == 1 &&
                        func_L39_006CCA88(ui->query, entry, 0)) {
                        s32 delta = abs_asm(func_L39_006CC238(3, entry->version) - skill);

                        if (best == -1 || delta < best) {
                            best = delta;
                            selected = entry;
                            if (best == 0) {
                                break;
                            }
                        }
                    }
                }
                if (selected) {
                    u8 query[0x1E0];
                    s32 id = selected->id;
                    s32 flags = selected->flags;
                    s32 value;
                    s32 mode;
                    u8 *screen;
                    s32 *menu;

                    func_L39_006CC120(query);
                    func_L39_006CC648(query, selected);
                    screen = (u8 *)D_L39_00247914[0xA4 / 4];
                    value = func_L39_006CC350(query, 2);
                    mode = selected->mode;
                    menu = D_L39_00247914;
                    *(s32 *)(screen + 0x2A8) = id;
                    *(s32 *)(screen + 0x2AC) = flags;
                    *(s32 *)(screen + 0x2B0) = value;
                    *(s32 *)(screen + 0x2B4) = mode;
                    menu[0x284 / 4] = 16;
                    ui->state = 2;
                    func_L39_006CC158(query, 2);
                } else {
                    s32 *menu = D_L39_00247914;
                    char *message = func_00381FF0(0x1766);

                    func_L39_006872E8(menu, message, D_L39_00248EA0, 4, 0, 0.6f);
                }
            } else {
                s32 *menu = D_L39_00247914;
                char *message = func_00381FF0(0x1766);

                func_L39_006872E8(menu, message, D_L39_00248EA0, 4, 0, 0.6f);
                ui->state = 0;
            }
        } else {
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - ui->time > 15000) {
                ui->state = 0;
            }
        }
        if (ui->state == 0) {
            u8 query[0x1E0];

            func_L39_006CC120(query);
            func_L39_006CC930(query);
            func_L39_006CC158(query, 2);
        }
    }
    return ui->state != 0;
}
/* localdecomp:end func_L39_006B2498 */
