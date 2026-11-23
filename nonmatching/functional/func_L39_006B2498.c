/* functional: high. Multiplayer quick-match step (state 1: show the game-type choice list, build and send the search query; state 2: when the browser is idle pick the open game with a matching client count and skill rating closest to ours, fill the join screen fields, else show the not-found message; 15 s timeout). Ported from the NTSC twin draft with PAL offsets, callees and D_ names rechecked against asm; only the 0.6f literal assembly differs (71 words). D_L39_00247914 type conflicts with earlier file context: use --no-context or match the file type when merging. */
#include "vu0.h"
typedef struct {
    u8 pad0[0x2A8]; s32 time, state, connection, mode; u8 query[0x1E0];
} UI_006B2498;
typedef struct {
    u8 pad0[0x1C]; s32 id; u16 min; u8 pad22[2]; u16 max; u8 pad26[6]; s32 version;
    u8 pad30[0x10]; s32 flags, type, mode;
} E_006B2498;
typedef struct { s32 unused, count; E_006B2498 **entries; } Group_006B2498;
typedef struct {
    u8 pad0[0x18]; s32 selected; u8 busy; u8 pad1D[0xF]; Group_006B2498 groups[1];
} Browser_006B2498;
typedef struct { u8 pad0[0x70]; Browser_006B2498 *browser; } Hub_006B2498;
typedef struct { u8 pad0[0xA4]; u8 *screen; } Menu_006B2498;
typedef struct { u8 pad0[0xC]; s32 clients; u8 pad10[0x78]; f32 first[4], second[4]; } Game_006B2498;
extern Hub_006B2498 *D_L39_0024D760;
__asm__(".extern D_L39_0024D760, 16");
extern Menu_006B2498 *D_L39_00247914;
__asm__(".extern D_L39_00247914, 16");
extern Game_006B2498 D_001A5CD0;
__asm__(".extern D_001A5CD0, 16");
extern u8 D_L39_00248EA0[];
extern void *func_00381FF0(s32);
extern s32 func_L39_00687800(void *, void *, void *, s32, s32);
extern void func_L39_006CC188(void *);
extern void func_L39_006CC8F0(void *, s32, s32, s32);
extern s32 func_L39_006DF598(f32, f32);
extern void func_L39_006CC930(void *);
extern void func_L39_006D5AB8(void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_L39_006CC120(void *);
extern void func_L39_006CC158(void *, s32);
extern s32 func_L39_006CCA88(void *, void *, s32);
extern s32 func_L39_006CC238(s32, s32);
extern void func_L39_006CC648(void *, void *);
extern s32 func_L39_006CC350(void *, s32);
extern void func_L39_006872E8(void *, void *, void *, s32, s32, f32);

s32 func_L39_006B2498(UI_006B2498 *ui) {
    Browser_006B2498 *browser = D_L39_0024D760->browser;
    if (ui->state == 1) {
        if (browser->busy == 0) {
            void *choices[4] = { func_00381FF0(0xFBF), func_00381FF0(0x1024), func_00381FF0(0x10E2), func_00381FF0(0x1026) };
            Menu_006B2498 *menu = D_L39_00247914;
            void *title = func_00381FF0(0xFEA);
            s32 choice = func_L39_00687800(menu, title, choices, 4, 0);
            if (choice < 0) { ui->state = 0; return 1; }
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
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - ui->time > 15000) ui->state = 0;
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
            if (browser->selected >= 0) group = &browser->groups[browser->selected];
            if (group) {
                s32 best = -1;
                s32 i = 0;
                E_006B2498 *selected = 0;
                s32 skill;
                ui->state = 0;
                skill = func_L39_006DF598(D_001A5CD0.first[ui->mode], D_001A5CD0.second[ui->mode]);
                for (; i < group->count; i++) {
                    E_006B2498 *entry = group->entries[i];
                    s32 id = entry->id, flags = entry->flags;
                    u16 min = entry->min, max = entry->max;
                    s32 type = entry->type;
                    if (id >= 0 && flags == 0 && max >= min + D_001A5CD0.clients && type == 1 && func_L39_006CCA88(ui->query, entry, 0)) {
                        s32 delta = abs_asm(func_L39_006CC238(3, entry->version) - skill);
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
                    Menu_006B2498 *menu;
                    func_L39_006CC120(query);
                    func_L39_006CC648(query, selected);
                    screen = D_L39_00247914->screen;
                    value = func_L39_006CC350(query, 2);
                    menu = D_L39_00247914;
                    *(s32 *)(screen + 0x2B4) = selected->mode;
                    *(s32 *)(screen + 0x2A8) = id;
                    *(s32 *)(screen + 0x2AC) = flags;
                    *(s32 *)(screen + 0x2B0) = value;
                    *(s32 *)((u8 *)menu + 0x284) = 16;
                    ui->state = 2;
                    func_L39_006CC158(query, 2);
                } else {
                    Menu_006B2498 *menu = D_L39_00247914;
                    void *message = func_00381FF0(0x1766);
                    func_L39_006872E8(menu, message, D_L39_00248EA0, 4, 0, 0.6f);
                }
            } else {
                Menu_006B2498 *menu = D_L39_00247914;
                void *message = func_00381FF0(0x1766);
                func_L39_006872E8(menu, message, D_L39_00248EA0, 4, 0, 0.6f);
                ui->state = 0;
            }
        } else {
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - ui->time > 15000) ui->state = 0;
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
