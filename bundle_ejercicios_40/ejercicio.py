N = 12

arr = [
   0xffffffff , 0x95555555 , 0xf4444444 , 0xf1111111 ,
   0xffffff00 , 0xf5005555 , 0x95444444 , 0xf1113311 ,
   0xff00ffff , 0xf5550055 , 0xa4444433 , 0xa1551111
]

suma = 0xffffffff
i = 0
n = 12
for i in range(n):
   if ( i & 0x1 ) == 0x1:
       suma &= arr[ i ]

print(f"Suma {suma:08x}")
