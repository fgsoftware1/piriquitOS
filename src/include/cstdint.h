#ifndef __CSTDINT_H
#define __CSTDINT_H

namespace std{
  using int8_t         = signed;
  using int16_t        = signed;
  using int32_t        = signed;
  using int64_t        = signed;
  
  using uint8_t        = unsigned;
  using uint16_t       = unsigned;
  using uint32_t       = unsigned;
  using uint64_t       = unsigned;
}
 
#define INTN_MIN        
#define INTN_MAX       
#define UINTN_MAX       
 
#define INT_FASTN_MIN    
#define INT_FASTN_MAX   
#define UINT_FASTN_MAX  
 
#define INT_LEASTN_MIN   
#define INT_LEASTN_MAX 
#define UINT_LEASTN_MAX 
 
#define INTMAX_MIN      
#define INTMAX_MAX      
#define UINTMAX_MAX     
 
#define INTPTR_MIN     
#define INTPTR_MAX      
#define UINTPTR_MAX      
 
#define PTRDIFF_MIN      
#define PTRDIFF_MAX    
#define SIZE_MAX        
 
#define SIG_ATOMIC_MIN 
#define SIG_ATOMIC_MAX 
 
#define WCHAR_MIN       
#define WCHAR_MAX        
 
#define WINT_MIN       
#define WINT_MAX       
 
#define INTN_C(value)   
#define UINTN_C(value)  
#define INTMAX_C(value) 
#define UINTMAX_C(value) 

#endif
