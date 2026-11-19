/* functional: high. Taken from the PAL near-miss draft (187 words differ: allocation and tail sharing only) after checking it against retail's assembly: both jump tables (states 0-7; params by state 0/1/2/6/7 -> D_L01_001DC760/758/768/770/750), the 0.02*frame step, the 96.0 sphere test, the 0.9 thresholds, the callback/removal paths and the swap-with-last removal. The calls to func_L01_00315350/003155A8/00314C90 pass the extra args retail leaves in registers (their matched definitions in this file take fewer). */
typedef int Q_00314158 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00314158;
typedef struct { s32 first, second, color; } Params_00314158;
extern Ent_003153D8 D_L01_00271B40[];
extern s32 D_L01_001E1740;
extern f32 D_L01_001DC778;
__asm__(".extern D_L01_001DC778, 4");
extern Params_00314158 D_L01_001DC750 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DC750, 8");
extern Params_00314158 D_L01_001DC758 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DC758, 8");
extern Params_00314158 D_L01_001DC760 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DC760, 8");
extern Params_00314158 D_L01_001DC768 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DC768, 8");
extern Params_00314158 D_L01_001DC770 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DC770, 8");
extern s32 D_L01_001DC75C;
__asm__(".extern D_L01_001DC75C, 16");
void func_L01_00314158(void) {
    extern void func_003C4138(f32 *, f32, f32);
    extern s32 func_L01_00459590(void *, s32, f32);
    extern void func_L01_00314620(u8 *, Params_00314158 *, s32, f32, s32);
    extern u8 **func_L01_00448FB8(u8 *);
    extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
    extern void func_L01_00314C90(u8 *, Params_00314158 *, f32);
    extern void func_L01_00315350(u8 *, Params_00314158 *, f32);
    extern void func_L01_003155A8(u8 *, Params_00314158 *, f32);
    extern void func_L01_00315800(s32, s32);
    extern void func_003C2880(u8 *);
    s32 i;
    f32 *phase;
    u8 *obj;
    Params_00314158 *params;
    V_00314158 sphere;
    u8 **twin;
    for(i=0;i<D_L01_001E1740;i++) {
        switch(D_L01_00271B40[i].pad8) {
        case 0: case 1: case 2: case 6: case 7: {
            u8 *object;
            object=D_L01_00271B40[i].obj;
            if(D_L01_00271B40[i].t!=0.0f) {
                func_003C4138(&D_L01_00271B40[i].t,0.0f,D_L01_001DC778*0.020000001415610313f);
                sphere=*(V_00314158 *)(object+0x10);
                sphere.w=5.0f;
                params=0;
                switch(D_L01_00271B40[i].pad8) {
                case 0: params=&D_L01_001DC760; break;
                case 1: params=&D_L01_001DC758; break;
                case 2: params=&D_L01_001DC768; break;
                case 6: params=&D_L01_001DC770; break;
                case 7: params=&D_L01_001DC750; break;
                }
                if(func_L01_00459590(&sphere,0,96.0f)>=0) {
                    func_L01_00314620(object,params,0,D_L01_00271B40[i].t,D_L01_00271B40[i].pad8);
                    twin=func_L01_00448FB8(object);
                    if(twin && *twin) func_L01_00314620(*twin,params,0,D_L01_00271B40[i].t,D_L01_00271B40[i].pad8);
                }
                func_L01_00315800(i,params->color);
                break;
            }
            if (*(void (**)(u8 *))D_L01_00271B40[i].pad10) {
                { u8 *rgb=(u8 *)&D_L01_00271B40[i].col;
                func_L01_0043B9E8(object,rgb[0],rgb[1],rgb[2]); }
                object[0x23]=128;
                *(u16 *)(object+0x34)&=~2;
                (*(void (**)(u8 *))D_L01_00271B40[i].pad10)(object);
            } else func_003C2880(object);
            goto removed;
        }
        case 3:
            phase=&D_L01_00271B40[i].t;
            obj=D_L01_00271B40[i].obj;
            if(*phase!=0.0f) {
                func_003C4138(phase,0.0f,D_L01_001DC778*0.020000001415610313f);
                func_L01_00314C90(obj,&D_L01_001DC758,*phase);
                goto update;
            }
            goto finished;
        case 4:
            phase=&D_L01_00271B40[i].t;
            obj=D_L01_00271B40[i].obj;
            if(*phase==0.0f) goto finished;
            func_003C4138(phase,0.0f,D_L01_001DC778*0.020000001415610313f);
            if(0.9f<=*phase) {
                func_L01_00315350(obj,&D_L01_001DC758,*phase);
                twin=func_L01_00448FB8(obj);
                if(twin && *twin) func_L01_00315350(*twin,&D_L01_001DC758,*phase);
            }
            goto update;
        case 5:
            phase=&D_L01_00271B40[i].t;
            obj=D_L01_00271B40[i].obj;
            if(*phase==0.0f) goto finished;
            func_003C4138(phase,0.0f,D_L01_001DC778*0.020000001415610313f);
            if(0.9f<=*phase) {
                func_L01_003155A8(obj,&D_L01_001DC758,*phase);
                twin=func_L01_00448FB8(obj);
                if(twin && *twin) func_L01_003155A8(*twin,&D_L01_001DC758,*phase);
            }
update:
            func_L01_00315800(i,D_L01_001DC75C);
            break;
finished:
            if (*(void (**)(u8 *))D_L01_00271B40[i].pad10) {
                { u8 *rgb=(u8 *)&D_L01_00271B40[i].col;
                func_L01_0043B9E8(obj,rgb[0],rgb[1],rgb[2]); }
                obj[0x23]=128;
                *(u16 *)(obj+0x34)&=~2;
                (*(void (**)(u8 *))D_L01_00271B40[i].pad10)(obj);
            } else func_003C2880(obj);
removed:
            { s32 n=D_L01_001E1740;
            Ent_003153D8 *base=D_L01_00271B40;
            Ent_003153D8 *last=(Ent_003153D8 *)((s32)base+(n<<5)-32);
            D_L01_001E1740=n-1;
            base[i]=*last; }
            break;
        }
    }
}
