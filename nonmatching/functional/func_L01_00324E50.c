/* functional: medium. 73 words differ (iterator and register allocation); control flow is a goto formulation of the retail loops. */
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0058;
extern s32 D_001DCA10_sda;
__asm__(".extern D_001DCA10_sda, 4");
typedef struct { u8 pad[0x58]; f32 weight; } Weight_00324E50;
typedef struct { u8 pad[0x68]; Weight_00324E50 *vars; } Moby_00324E50;
__asm__(".extern D_L01_001E001C, 16");
__asm__(".extern D_L01_001E0058, 16");
typedef struct { u8 p0[8]; u8 *f8; s32 fC; u8 p10[12]; s32 f1C; u8 p20[16]; s32 f30; u8 p34[12]; s32 f40; u8 p44[16]; s32 f54; s32 f58; s32 f5C; u8 p60[20]; s32 f74; u8 p78[12]; s32 f84; s32 f88; } Vars_00324E50;
void func_L01_00324E50(u8 *m, u8 *arg) {
    extern void func_L01_00325110(u8 *, u8 *);
    extern void func_L01_00325570(u8 *, u8 *);
    extern void func_L01_00325708(u8 *, u8 *);
    extern void func_L01_004450F0(void *, s32, s32);
    Vars_00324E50 *v=(Vars_00324E50 *)arg;
    s16 *p;
    u8 *o;
    s32 index, count, bad, enabled;
    f32 value;
    func_L01_00325110(m,(u8 *)v);
    enabled=v->f40;
    D_001DCA10_sda=(s32)m;
    if (enabled) {
        v->f8=D_L01_001E001C+(((u16)*D_L01_0021DE20[v->f1C] & 0x7FFF)<<8);
    } else v->f8=0;
    v->fC=-1;
    v->f5C=-1;
    v->f84=-1;
    v->f30=0;
    v->f74=0;
    v->f54=0;
    v->f88=0;
    m[0x30]=255;
    func_L01_00325570(m,(u8 *)v);
    func_L01_00325708(m,(u8 *)v);
    if (v->f58) {
        index=v->f1C;
        p=D_L01_0021DE20[index];
        bad=0; count=0;
        goto first_test;
first_body:
        o=D_L01_001E001C+(((u16)*p&0x7FFF)<<8);
        if(!o) goto first_done;
        count++;
        if (((Moby_00324E50 *)o)->vars->weight<0) bad=1;
        p++;
first_test:
        if((u8)index==255 || index>D_L01_001E0058 || !p) goto first_done;
        if(p[-1]>=0 || p==D_L01_0021DE20[index]) goto first_body;
first_done:
        if(bad) {
            u8 *base;
            s32 max;
            s16 **table=D_L01_0021DE20;
            value=1.0f/(f32)count;
            index=v->f1C;
            p=table[index];
            max=D_L01_001E0058;
            base=D_L01_001E001C;
            if((u8)index!=255 && index<=max && p) {
                do {
                    o=base+(((u16)*p&0x7FFF)<<8);
                    if(!o) break;
                    ((Moby_00324E50 *)o)->vars->weight=value;
                    p++;
                    index=v->f1C;
                } while((u8)index!=255 && index<=max && p && (p[-1]>=0 || p==table[index]));
            }
        }
    }
finish:
    func_L01_004450F0(m,1,-1);
}
