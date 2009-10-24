#define CHECK_MALLOC(x)					\
  do {							\
    if((x) == NULL){					\
      printf("Error! memory is not available\n");	\
      exit(0);						\
    }							\
  }while(0);

#define ASSERT(x,msg)					\
  do {							\
    if(!(x)){						\
      printf("Error! assertion '%s' failed!\n", (msg));	\
    }							\
  }while(0);						
