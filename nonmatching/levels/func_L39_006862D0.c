/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_006837B0, the NTSC-U twin of func_L39_006862D0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/39_multiplayer_menu/L39_00686138.c's current line.
 * Worker's note: 283 diff; best log func_L39_006837B0.check01.log; permitted GNU assembler loads 1.6f/0.6f from lit4 where retail uses inline 0x3FCCCCCD/0x3F19999A; no flags_alt; vtable/menu source retained; forbidden flags not tried
 */
#include "common.h"

/* localdecomp:start func_L39_006837B0 */
typedef struct Child_6837B0 Child_6837B0;
typedef struct {
    u8 pad0[0x14];
    s32 (*update)(Child_6837B0 *,s32);
    u8 pad18[0xF8-0x18];
    void (*fallback)(Child_6837B0 *,s32);
} VTable_6837B0;
struct Child_6837B0 {
    u8 pad0[0x60];
    VTable_6837B0 *vtable;
    u8 pad64[0x108-0x64];
    s32 kind;
};
typedef struct {
    u8 pad0[0x110];
    Child_6837B0 *children[44];
    s32 codes[44];
    s32 selected, overlay, unused, timer;
    u8 blocked;
} Menu_6837B0;
extern u8 D_001A5E50[];
extern s32 D_001A612C[];
extern s32 D_L39_002412E4[], D_L39_004AE188[];
extern u8 D_L39_00372BC0[], D_L39_00247B00[];
extern s32 D_L39_003D2980[];
extern s32 D_001DC1E4_sda;
extern u8 *D_001E1FD0_sda;
extern void func_L39_00686A68(void *);
extern s32 func_L39_00683618(void *,s32);
extern s32 func_00120884(void *);
extern void func_L39_005945F0(void *,void *,s32);
extern u8 *func_0037DF98(s32);
extern s32 func_L39_006847C8(void *,void *,void *,s32,s32,f32);
extern void func_L39_006855C8(void *,void *,void *);
extern void func_L01_00512AB0(s32,s32,s32);
extern void func_L01_00513548(s32,f32,f32);
extern s32 func_L39_00684EC0(void *,s32);
extern s32 func_001962E8(void);
extern void func_001375B0(void *,void *,s32);
extern void func_001962D8(s32);
extern void func_L39_00684320(void *);

void func_L39_006837B0(Menu_6837B0 *menu) {
    u8 a[0x40],b[0x40],c[0x40];
    u8 *text;
    Child_6837B0 *child;
    s32 event,input,length;
    func_L39_00686A68(menu);
    event=func_L39_00683618(menu,D_L39_002412E4[0]);
    if (menu->overlay==-1 && D_001A5E50[0x85D] && menu->codes[menu->selected]!=0x21) {
        text=D_001A5E50+0x87C;
        if (*(s32 *)(D_001A5E50+0x868)==2) {
            length=func_00120884(text);
            if (length>0x3FF) length=0x3FF;
            func_L39_005945F0(D_L39_00372BC0,text,length);
            text=D_L39_00372BC0;
        }
        switch (D_001A5E50[0x864]) {
        case 1: text=func_0037DF98(0x1B91); break;
        case 2: text=func_0037DF98(0x1B92); break;
        case 3: text=func_0037DF98(0x1B93); break;
        }
        D_001A5E50[0x85D]=0;
        func_L39_006847C8(menu,D_L39_00247B00,text,4,1,1.6f);
        if (D_001A5E50[0x864]>=2) {
            func_L39_006855C8(menu,a,b);
            return;
        }
    }
    if (menu->selected>=0 || menu->overlay>=0) {
        if (menu->overlay>=0) {
            func_L01_00512AB0(D_L39_003D2980[0x44/4],1,0);
            func_L01_00512AB0(D_L39_003D2980[0x4C/4],1,0);
            func_L01_00512AB0(D_L39_003D2980[0x48/4],1,0);
            func_L01_00513548(D_L39_003D2980[0x34/4],1.0f,1.0f);
            func_L01_00513548(D_L39_003D2980[0x38/4],1.0f,1.0f);
            child=menu->children[menu->overlay];
            if (!child->vtable->update(child,event)) {
                child=menu->children[menu->overlay];
                child->vtable->fallback(child,event);
            }
            if (menu->selected>=0 && menu->children[menu->selected]->kind==0x21) {
                child=menu->children[menu->selected];
                child->vtable->update(child,0);
            }
        } else if (!func_L39_00684EC0(menu,event)) {
            child=menu->children[menu->selected];
            if (!child->vtable->update(child,event)) {
                child=menu->children[menu->selected];
                child->vtable->fallback(child,event);
            }
        }
    }
    if (D_001DC1E4_sda) {
        input=*(s32 *)(D_001E1FD0_sda+0x14);
        *(s32 *)(D_001E1FD0_sda+0x14)=0;
        if (!input && !D_001A612C[0] && !func_001962E8()) {
            menu->timer=0;
        } else if (!menu->blocked) {
            if (*(s32 *)(D_001A5E50+0x2DC)==2 || input==8 || input==2) {
                if (++menu->timer>120 && menu->overlay<0) {
                    menu->timer=0;
                    func_001375B0(a,c,0x40);
                    text=func_0037DF98(0x1189);
                    if (func_L39_006847C8(menu,text,D_L39_00247B00,0x30,0,0.6f)==0x20) {
                        func_L39_006855C8(menu,a,c);
                        return;
                    }
                    *(s32 *)(D_001A5E50+0x2DC)=0;
                    func_001962D8(0);
                    menu->timer=0;
                }
            } else if (input && input!=0x3E && input!=0x2E && input!=0x12 && input!=0x2F && input!=0x27 && input!=0x26 && input!=0x4B && input!=0xF) {
                text=func_0037DF98(D_L39_004AE188[input]);
                func_L39_006847C8(menu,D_L39_00247B00,text,4,0,0.6f);
            }
        }
        func_L39_00684320(menu);
    }
}
/* localdecomp:end func_L39_006837B0 */
