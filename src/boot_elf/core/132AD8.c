#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_00132AD8();
/* --- end of declarations from other files --- */

/* declarations of 1301D8.c's earlier functions (tools/port_from_us.py) */
typedef struct {
    u8 pad0[0x184];
    int f184;
    int f188;
} S_130210;
typedef struct {
    int f0;
    u8 pad4[0x10 - 4];
    int f10;
} Pic_130AA0;
typedef struct {
    int f0;
    int pad4;
    int f8;
    int fC;
    int f10;
    u8 pad14[0x140 - 0x14];
} Blk_130AA0;
typedef struct {
    u8 pad0[0x12C];
    int f12C;
    u8 pad130[0x13C - 0x130];
    int f13C;
    u8 pad140[0x184 - 0x140];
    int f184;
    u8 pad188[0x1D0 - 0x188];
    Pic_130AA0 *f1D0;
    u8 pad1D4[0x1E0 - 0x1D4];
    Pic_130AA0 *f1E0;
    u8 pad1E4[0x1F0 - 0x1E4];
    Pic_130AA0 *f1F0;
    u8 pad1F4[0x6C8 - 0x1F4];
    Blk_130AA0 blk[1];
    u8 pad808[0x820 - 0x808];
    int f820;
} S_130AA0;
extern char D_00151CF0[];
void func_0013A150(void *s, char *fmt, int x);
void func_00130398(S_130AA0 *s, int x, int y, int flags, int mode, int *mv, int *fs, int a7);
void func_00132D48();
typedef struct {
    s32 x00;                        
    s32 x04;                        
    u8 pad08[0x28 - 0x08];
    void (*cbA[4])(void *);         
    void (*cbB[4])(void *);         
    u8 a[4][0x1C];                  
    u8 b[4][0x1C];                  
    s32 x128;                       
    s32 x12C;                       
    s32 x130;                       
    s32 x134;                       
    s32 x138;                       
    s32 x13C;                       
} E_131178;
typedef struct {
    u8 pad0[0x5A0];
    E_131178 e[2];                  
    u8 pad820[0x830 - 0x820];
    s32 x830;                       
} S_131178;
extern s32 func_0013A0F8();
extern char D_00151D18[];
extern void func_00132B98();
typedef struct {
    u8 pad0[0x13C];
    int f13C;
    int f140;
    u8 pad144[0x184 - 0x144];
    int f184;
    u8 pad188[0x820 - 0x188];
    int f820;
    int f824;
    u8 pad828[0x848 - 0x828];
    int f848;
    int f84C;
    u8 pad850[0x868 - 0x850];
    int f868;
    u8 pad86C[0x878 - 0x86C];
    int f878;
} S_131398;
extern char D_00151D30[];
int func_001315D8_00131398(void *s, int n);
void func_00132A98_00131398(void *s);
int func_00135DC8(int x);
void func_00139F90(void);
void func_0013A030(void *s);
void func_00131178_00131398(void *s, int first);
extern s32 func_0013A0F8();
typedef struct {
    u8 pad0[0x12C];
    s32 x12C;           
    u8 pad130[0x6DC - 0x130];
    s32 x6DC;           
    u8 pad6E0[0x820 - 0x6E0];
    s32 x820;           
    u8 pad824[0x848 - 0x824];
    s32 x848;           
    s32 x84C;           
    u8 pad850[0x868 - 0x850];
    s32 x868;           
    u8 pad86C[0x878 - 0x86C];
    s32 x878;           
} S_1315D8;
extern s32 func_00133C58();
extern void func_00132A98();
extern void func_00135DC8_001315D8();
extern void func_00139F90();
extern void func_0013A030();
extern s32 func_00132970();
extern s32 func_00132428();
extern s32 func_00131ED0();
extern s32 func_00130AA0();
extern void func_00131178();
extern s32 func_0013A0F8();
extern char D_00151D50[];
typedef struct {
    u8 pad0[0x12C];
    s32 x12C;
    u8 pad1[0x828 - 0x130];
    s32 x828;
    u32 x82C;
    u8 pad2[0x848 - 0x830];
    s32 x848;
    s32 x84C;
} S_131908;
extern void func_00132A98_00131908(S_131908 *);
extern u64 func_00132708_00131908(S_131908 *);
extern s32 func_00132888_00131908(S_131908 *, s32);
#define IPU_CMD_131908 ((volatile u32 *)0x10002000)
#define IPU_BP_131908  ((volatile u32 *)0x10002020)
#define IPU_TOP_131908 ((volatile s64 *)0x10002030)
typedef struct {
    s32 x;
    s32 y;
} Mv_131D30;
extern s32 func_00132888_00131D30();
extern void func_00131908();
typedef struct {
    s32 f0;
    u8 pad4[0x138 - 4];
    s32 f138;
    u8 pad13C[0x140 - 0x13C];
} Blk_131ED0;
typedef struct {
    u8 pad0[0x12C];
    s32 f12C;
    u8 pad130[0x160 - 0x130];
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
    s32 f170;
    s32 f174;
    s32 f178;
    s32 f17C;
    s32 f180;
    s32 f184;
    s32 f188;
    s32 f18C;
    s32 f190;
    u8 pad194[0x1C0 - 0x194];
    s32 f1C0;
    s32 f1C4;
    u8 pad1C8[0x5A4 - 0x1C8];
    Blk_131ED0 blk[1];
    u8 pad6E4[0x820 - 0x6E4];
    s32 f820;
    s32 f824;
    s32 f828;
    s32 f82C;
    u8 pad830[0x848 - 0x830];
    s32 f848;
    s32 f84C;
    u8 pad850[0x858 - 0x850];
    s32 f858;
} S_131ED0;
extern void func_00132A98();
extern long func_00132708();
extern s32 func_0013A0F8();
extern s32 func_00132888_00131ED0();
extern void func_00131D30();
extern void func_00131908();
extern void func_00132AD0();
extern void func_00133BB8();
extern char D_00151DA0[];
typedef struct {
    u8 pad0[0x12C];
    s32 x12C;           
    u8 pad130[0x828 - 0x130];
    s32 x828;           
    s32 x82C;           
    u8 pad830[0x848 - 0x830];
    s32 x848;           
    s32 x84C;           
    u8 pad850[0x858 - 0x850];
    s32 x858;           
} S_132428;
extern void func_00132A98_00132428(S_132428 *);
extern long func_00132708_00132428(S_132428 *);
extern s32 func_00132970(S_132428 *, s32);
extern void func_00132AD0(S_132428 *, s32);
extern void func_0013A150_00132428(S_132428 *, char *, s32);
extern char D_00151DC0[];
typedef struct {
    u8 pad0[0x82C];
    int f82C;
    u8 pad830[0x868 - 0x830];
    int f868;
    u8 pad86C[0x878 - 0x86C];
    int f878;
} S_1325A0;
int func_00135DC8(int x);
void func_00139F90(void);
typedef struct {
    u8 pad0[0x82C];
    s32 f82C;
    u8 pad830[0x868 - 0x830];
    s32 f868;
    u8 pad86C[0x878 - 0x86C];
    s32 f878;
} S_132708;
extern s32 func_00135DC8_00132708(s32);
extern void func_00139F90(void);
extern void func_00132A98();
extern long func_00132708();
extern void func_00132A98();

/* localdecomp:start func_00132AD8 */
typedef struct {
    u8 pad[0x1C];
    s32 x1C;
    u8 pad20[0x120];
} Pic_132AD8;

typedef struct {
    u8 pad[0x160];
    s32 x160;
    u8 pad164[0x20];
    s32 x184;
    u8 pad188[0x38];
    s32 x1C0;
    u8 pad1C4[0x4FC];
    Pic_132AD8 pics[1];
} Dec_132AD8;

typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    s32 x10;
    s32 x14;
} Rect_132AD8;

extern char D_00151D70[];
extern s32 func_0013A0F8();

s32 func_00132AD8(Dec_132AD8 *d, Rect_132AD8 *r, s32 *a, s32 *b, s32 *flags) {
    s32 ret;
    s32 t;

    ret = 1;
    d->pics[*(s32 *)((u8 *)d + 0x820)].x1C = 1;
    d->x1C0 = 1;
    if (d->x160 == 2) {
        r->x14 = 0;
        r->x10 = 0;
        r->x4 = 0;
        r->x0 = 0;
    }
    if (d->x184 == 3) {
        *a = 2;
    } else {
        *a = 1;
        t = d->x184 == 2;
        b[1] = t;
        b[0] = t;
    }
    if (d->x160 == 1) {
        func_0013A0F8(d, D_00151D70);
        ret = 0;
    }
    *flags &= ~1;
    return ret;
}
/* localdecomp:end func_00132AD8 */
