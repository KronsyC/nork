#ifndef NORK_DATABASE_INDEXABLE_H
#define NORK_DATABASE_INDEXABLE_H

#include<string>
namespace nork{

  template<typename T>
  concept Indexable = requires(T val){
    { val.getId() } -> std::same_as<std::string>;
  };
}

#endif // !NORK_DATABASE_INDEXABLE_H
