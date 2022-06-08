#ifndef _BITMATH_
#define _BITMATH_

//#define setBit(x, b) (x) |= (1 << (b))
//#define clrBit(x, b) (x) &= ~(1 << (b))
//#define togBit(x, b) (x) ^= (1 << (b))
////#define getBit(x, b) (x) &= (1 << (b))
//#define getBit(x, b) ((x >> b) & 0x01)

#define setBit(Var,BitNo) Var|=(1<<BitNo)
#define clrBit(x,b) ((x)&=~(1<<(b)))
#define togBit(x,b) ((x)^=(1<<(b)))
#define getBit(x,b) (1&((x)>>(b)))

#endif
