/* functional: high. functional */
extern s32 D_L01_001D88D8;
extern s32 D_L01_001D88DC;
extern s32 D_L01_001D87A0[];
extern s32 D_L01_001D87C0[];
extern s32 D_001D4C60[];
extern s32 D_001D4C80[];
extern void func_003BB468(s32);
extern Obj *func_003B42F8(s32);
extern void func_003A2750(s32);
extern void func_L01_00517918(s32);
extern void func_L01_00487F50(s32 *, s32 *);

void func_L01_00489F00(void) {
    Obj *o;

    func_003BB468(D_L01_001D88D8);
    func_003BB468(D_L01_001D88DC);
    o = func_003B42F8(0);
    o->vt->fn(o);
    func_003A2750(1);
    func_L01_00517918(0x10);
    func_L01_00517918(0x11);
    func_L01_00517918(0x13);
    func_L01_00487F50(D_L01_001D87A0, D_001D4C60);
    func_L01_00487F50(D_L01_001D87C0, D_001D4C80);
}
