/* functional: high. Based on the PAL Codex near-miss draft, checked line by line against the PAL boot_elf assembly; fixed: func_00390FD8 now has a real prototype (s32, s32, s32, f32) under the alias func_00390FD8_bfF5C8 (the unit declares it unprototyped, which promotes the scale to double and adds a conversion call). 39 words differ from retail, all FP register allocation/scheduling. */
typedef struct {
    u8 pad[0x10];
    f32 x,y,w,h,dx,dy;
    u8 pad28[0x3C-0x28];
    s32 font;
    u8 pad40[8];
    f32 size,scale;
    u8 pad50[8];
    s32 alignment;
    f32 width,height;
} Text_003F05C8;
typedef struct { f32 x0,y0,x1,y1; } Rect_003F05C8;
extern f32 D_001D9698;
extern f32 D_001D96B0_bfF5C8[];
extern f32 D_001D9698;
void func_003F05C8(Text_003F05C8 *p, Rect_003F05C8 *clip, Rect_003F05C8 *out, s32 align) {
    extern void func_0038E530(s32);
    extern s32 func_00391100(s32, s32, f32);
    extern s32 func_003F0388(void *, s32);
    extern f32 func_00390FD8_bfF5C8(s32, s32, s32, f32);
    extern void func_003EDEF8(void *, s32 *, s32 *);
    extern s32 func_003EDEB0(void *, s32);
    extern void func_003E7658(f32 *, f32 *);
    extern s32 func_0011A264(void *, s32, s32);
    Rect_003F05C8 tmp;
    s32 ha,va;
    f32 sx,sy;
    f32 ydiv,yoff,xoff,font,xdiv;
    switch (p->alignment) {
    case 1: func_0038E530(1); break;
    case 2: func_0038E530(0); break;
    case 0:
    default: func_0038E530(0); break;
    }
    if (p->font) font = (f32)func_00391100(p->font,-1,1.0f) / D_001D9698;
    else font = 0.0f;
    ydiv=2.0f; yoff=0.0f; xdiv=2.0f; xoff=0.0f;
    if (align) {
        ha=0; va=0;
        func_003EDEF8(p,&ha,&va);
        if (ha != 3) {
            if (ha != 1) xdiv=-2.0f;
            xoff=1.0f;
        }
        if (va != 3) {
            ydiv=2.0f;
            if (va == 2) ydiv=-2.0f;
            yoff=1.0f;
        }
    }
    p->width=p->w; p->height=p->h;
    if (func_003F0388(p,1)) {
        f32 factor;
        if (p->font) factor=func_00390FD8_bfF5C8(p->font,-1,(s32)(p->size*D_001D9698),p->scale);
        else factor=0.0f;
        p->width *= factor;
        p->height *= factor;
    }
    if (func_003EDEB0(p,0x2000)) {
        sx=0.0f; sy=0.0f;
        func_003E7658(&sx,&sy);
        p->width *= sx;
        p->height *= sy;
    }
    {
        f32 hw = p->width * font / xdiv;
        f32 hh = p->height * D_001D96B0_bfF5C8[0] / ydiv;
        f32 ox = hw*xoff, oy=hh*yoff;
        out->x0=p->x-hw+ox;
        out->y0=p->y-hh+oy;
        out->x1=p->x+hw+ox;
        out->y1=p->y+hh+oy;
    }
    if (clip->x0!=0.0f || clip->x1!=1.0f || clip->y0!=0.0f || clip->y1!=1.0f) {
    {
        f32 x0=out->x0, y0=out->y0, x1=out->x1, y1=out->y1;
        f32 d0=(clip->x1-clip->x0)*x0+clip->x0;
        out->x0=d0;
        d0-=x0;
        out->x1=x1+d0;
        d0=(clip->y1-clip->y0)*y0+clip->y0;
        out->y0=d0;
        d0-=y0;
        out->y1=y1+d0;
    }
    if (func_003EDEB0(p,0x40)) {
        f32 dx=p->dx, dy=p->dy;
        func_0011A264(&tmp,0,16);
        tmp=*out;
        tmp.x0+=dx; tmp.x1+=dx; tmp.y0+=dy; tmp.y1+=dy;
        out->x0=(tmp.x0 < out->x0) ? tmp.x0 : out->x0;
        out->x1=(out->x1 < tmp.x1) ? tmp.x1 : out->x1;
        out->y1=(out->y1 < tmp.y1) ? tmp.y1 : out->y1;
        out->y0=(tmp.y0 < out->y0) ? tmp.y0 : out->y0;
    }
    }
}
