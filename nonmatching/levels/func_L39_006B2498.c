/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_006AFB30, the NTSC-U twin of func_L39_006B2498, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/39_multiplayer_menu/L39_006B2120.c's current line.
 * Worker's note: 71 diff; 4 checks; documented inline-literal assembler mismatch: 0.6f becomes lwc1 via .lit4 with permitted GNU-as flags, retail inline lui/ori/mtc1 at 0x40C and 0x44C; no flags_alt; no unlisted flags tried; selected-screen store order also differs; best log func_L39_006AFB30.check-03.log
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_006AFB30 */
typedef struct {
    u8 pad0[0x2A8]; s32 time, state, connection, mode; u8 query[0x1E0];
} UI_006AFB30;
typedef struct {
    u8 pad0[0x1C]; s32 id; u16 min; u8 pad22[2]; u16 max; u8 pad26[6]; s32 version;
    u8 pad30[0x10]; s32 flags, type, mode;
} E_006AFB30;
typedef struct { s32 unused, count; E_006AFB30 **entries; } Group_006AFB30;
typedef struct {
    u8 pad0[0x18]; s32 selected; u8 busy; u8 pad1D[0xF]; Group_006AFB30 groups[1];
} Browser_006AFB30;
typedef struct { u8 pad0[0x70]; Browser_006AFB30 *browser; } Hub_006AFB30;
typedef struct { u8 pad0[0xA4]; u8 *screen; } Menu_006AFB30;
typedef struct { u8 pad0[0xC]; s32 clients; u8 pad10[0x78]; f32 first[4], second[4]; } Game_006AFB30;
extern Hub_006AFB30 *D_L39_0024D860;
__asm__(".extern D_L39_0024D860, 16");
extern Menu_006AFB30 *D_001DC1E4_sda;
extern Menu_006AFB30 *D_L39_00247A74;
__asm__(".extern D_L39_00247A74, 16");
extern Game_006AFB30 D_001A5E50;
__asm__(".extern D_001A5E50, 16");
extern u8 D_L39_00248FE8[];
extern void *func_0037DF98(s32);
extern s32 func_L39_00684CE0(void *, void *, void *, s32, s32);
extern void func_L39_006C9698(void *);
extern void func_L39_006C9E00(void *, s32, s32, s32);
extern s32 func_L39_006DCA38(f32, f32);
extern void func_L39_006C9E40(void *);
extern void func_L39_006D3328(void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_L39_006C9630(void *);
extern void func_L39_006C9668(void *, s32);
extern s32 func_L39_006C9F98(void *, void *, s32);
extern s32 func_L39_006C9748(s32, s32);
extern void func_L39_006C9B58(void *, void *);
extern s32 func_L39_006C9860(void *, s32);
extern void func_L39_006847C8(void *, void *, void *, s32, s32, f32);

s32 func_L39_006AFB30(UI_006AFB30 *ui) {
    Browser_006AFB30 *browser = D_L39_0024D860->browser;
    if (ui->state == 1) {
        if (browser->busy == 0) {
            void *choices[4] = { func_0037DF98(0xFBF), func_0037DF98(0x1024), func_0037DF98(0x10E2), func_0037DF98(0x1026) };
            Menu_006AFB30 *menu = D_001DC1E4_sda;
            void *title = func_0037DF98(0xFEA);
            s32 choice = func_L39_00684CE0(menu, title, choices, 4, 0);
            if (choice < 0) { ui->state = 0; return 1; }
            ui->mode = 3;
            func_L39_006C9698(ui->query);
            func_L39_006C9E00(ui->query, 12, 2, 0);
            if (choice == 1) {
                func_L39_006C9E00(ui->query, 17, 2, 0);
                ui->mode = 0;
            } else if (choice == 2) {
                func_L39_006C9E00(ui->query, 17, 2, 1);
                ui->mode = 2;
            } else if (choice == 3) {
                func_L39_006C9E00(ui->query, 17, 2, 2);
                ui->mode = 1;
            }
            func_L39_006C9E00(ui->query, 3, 0, func_L39_006DCA38(D_001A5E50.first[ui->mode], D_001A5E50.second[ui->mode]) + 2);
            func_L39_006C9E40(ui->query);
            func_L39_006D3328(browser);
            ui->time = (s32)func_00130760(func_0012DCB0(), 0x24000);
            ui->state = 2;
        } else {
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - ui->time > 15000) ui->state = 0;
        }
        if (ui->state == 0) {
            u8 query[0x1E0];
            func_L39_006C9630(query);
            func_L39_006C9E40(query);
            func_L39_006C9668(query, 2);
        }
    }
    if (ui->state == 2) {
        if (browser->busy == 0) {
            Group_006AFB30 *group = 0;
            if (browser->selected >= 0) group = &browser->groups[browser->selected];
            if (group) {
                s32 best = -1;
                s32 i = 0;
                E_006AFB30 *selected = 0;
                s32 skill;
                ui->state = 0;
                skill = func_L39_006DCA38(D_001A5E50.first[ui->mode], D_001A5E50.second[ui->mode]);
                for (; i < group->count; i++) {
                    E_006AFB30 *entry = group->entries[i];
                    s32 id = entry->id, flags = entry->flags;
                    u16 min = entry->min, max = entry->max;
                    s32 type = entry->type;
                    if (id >= 0 && flags == 0 && max >= min + D_001A5E50.clients && type == 1 && func_L39_006C9F98(ui->query, entry, 0)) {
                        s32 delta = abs_asm(func_L39_006C9748(3, entry->version) - skill);
                        if (best == -1 || delta < best) {
                            best = delta; selected = entry;
                            if (best == 0) break;
                        }
                    }
                }
                if (selected) {
                    u8 query[0x1E0];
                    s32 id = selected->id;
                    s32 flags = selected->flags;
                    s32 value;
                    u8 *screen;
                    Menu_006AFB30 *menu;
                    func_L39_006C9630(query);
                    func_L39_006C9B58(query, selected);
                    screen = D_L39_00247A74->screen;
                    value = func_L39_006C9860(query, 2);
                    menu = D_L39_00247A74;
                    *(s32 *)(screen + 0x2B4) = selected->mode;
                    *(s32 *)(screen + 0x2A8) = id;
                    *(s32 *)(screen + 0x2AC) = flags;
                    *(s32 *)(screen + 0x2B0) = value;
                    *(s32 *)((u8 *)menu + 0x284) = 16;
                    ui->state = 2;
                    func_L39_006C9668(query, 2);
                } else {
                    Menu_006AFB30 *menu = D_L39_00247A74;
                    void *message = func_0037DF98(0x1766);
                    func_L39_006847C8(menu, message, D_L39_00248FE8, 4, 0, 0.6f);
                }
            } else {
                Menu_006AFB30 *menu = D_L39_00247A74;
                void *message = func_0037DF98(0x1766);
                func_L39_006847C8(menu, message, D_L39_00248FE8, 4, 0, 0.6f);
                ui->state = 0;
            }
        } else {
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - ui->time > 15000) ui->state = 0;
        }
        if (ui->state == 0) {
            u8 query[0x1E0];
            func_L39_006C9630(query);
            func_L39_006C9E40(query);
            func_L39_006C9668(query, 2);
        }
    }
    return ui->state != 0;
}
/* localdecomp:end func_L39_006AFB30 */
