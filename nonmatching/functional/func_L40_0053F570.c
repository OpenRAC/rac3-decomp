/* functional: high. Spawns a timed effect entry: takes a free slot of the 0x44-byte table D_L40_0033F2E0 (func_L40_0053F498), looks up its parameter row (func_L39_0066C428(type) into D_L40_00340030, stride 16), uses the given object (index<<8 from the object table, releasing any entry already tied to it via func_L40_0053F508, clearing its +0x20) or allocates one with func_003C24B0(type,0x400), fills the entry (callback D_L40_00246250, kind, state 1, times, params from the row, value, value2, empty list head) and links it at obj+0x90 before the empty callback func_L39_0067FAA8; returns the object. Built from the PAL asm; the NTSC draft of the twin was a structural guide only. Compiles near the retail shape. */
typedef struct Spawn_0053F570 {
    int value;
    unsigned char pad04[0x10];
    void *callback;
    unsigned char *moby;
    int time;
    int pad24;
    int a;
    int b;
    unsigned char kind;
    unsigned char state;
    unsigned char pad32[6];
    int head;
    int value2;
    int time2;
} Spawn_0053F570;

typedef struct Param_0053F570 {
    int unused;
    int a;
    int b;
    int c;
} Param_0053F570;

extern Param_0053F570 D_L40_00340030[];
extern unsigned char D_L40_00246250[];
extern int D_001A5DF8[];
extern unsigned char *D_L40_0024845C[];
extern int func_L40_0053F508(int);
extern unsigned char *D_001DCD4C_sda;
extern int func_L40_0053F498(void);
extern int func_L39_0066C428(int);
extern unsigned char *func_003C24B0(int, int);
extern void func_L39_0067FAA8(void);

unsigned char *func_L40_0053F570(int type, int value, int value2, int kind, unsigned char *obj) {
    Spawn_0053F570 *e;
    int i;
    int j;

    i = func_L40_0053F498();
    if (i < 0) {
        return 0;
    }
    j = func_L39_0066C428(type);
    if (j < 0) {
        return 0;
    }
    if ((int)obj == -1) {
        obj = func_003C24B0(type, 0x400);
        if (obj == 0) {
            return 0;
        }
    } else {
        obj = (unsigned char *)((int)obj << 8);
        func_L40_0053F508((int)(D_001DCD4C_sda + (int)obj));
        obj = obj + (int)D_L40_0024845C[0];
        obj[0x20] = 0;
    }
    e = (Spawn_0053F570 *)((unsigned char *)D_L40_0033F2E0 + i * 0x44);
    e->callback = D_L40_00246250;
    e->kind = kind;
    e->moby = obj;
    e->state = 1;
    e->time = D_001A5DF8[0];
    e->a = D_L40_00340030[j].a;
    e->value = value;
    e->b = D_L40_00340030[j].b;
    e->value2 = value2;
    e->time2 = D_001A5DF8[0];
    e->head = 0;
    *(Spawn_0053F570 **)(obj + 0x90) = e;
    func_L39_0067FAA8();
    return obj;
}
