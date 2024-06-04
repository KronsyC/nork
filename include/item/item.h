// Copyright (c) 2023 Samir Bioud
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.
//

#ifndef NORK_ITEM_H
#define NORK_ITEM_H

#include "duck.h"
#include "encounter.h"
#include "json.hpp"
#include <iostream>

namespace nork {

class Item {
  public:
    // Constructors
    Item(DuckInstance duck) : kind(ItemKind::Duck) { new (&data.duck) DuckInstance(std::move(duck)); }

    Item(EncounterInstance encounter) : kind(ItemKind::Encounter) {
        new (&data.encounter) EncounterInstance(std::move(encounter));
  }

  DuckInstance* duck(){
    if(this->kind == ItemKind::Duck) return &this->data.duck;
    else return nullptr;
  }

  EncounterInstance* encounter(){
    if(this->kind == ItemKind::Encounter) return &this->data.encounter;
    else return nullptr;
  }

    // Copy Constructor
    Item(const Item& other) : kind(other.kind) {
        switch (other.kind) {
        case ItemKind::Duck:
            new (&data.duck) DuckInstance(other.data.duck);
            break;
        case ItemKind::Encounter:
            new (&data.encounter) EncounterInstance(other.data.encounter);
            break;
        }
    }

    // Destructor
    ~Item() { destroy(); }

    // Copy Assignment Operator
    Item& operator=(const Item& other) {
        if (this != &other) {
            destroy(); // Clean up current data

            kind = other.kind;
            switch (other.kind) {
            case ItemKind::Duck:
                new (&data.duck) DuckInstance(other.data.duck);
                break;
            case ItemKind::Encounter:
                new (&data.encounter) EncounterInstance(other.data.encounter);
                break;
            }
        }
        return *this;
    }

  private:
    enum class ItemKind { Duck, Encounter };
    ItemKind kind;

    union ItemData {
        DuckInstance duck;
        EncounterInstance encounter;

        ItemData() {}
        ~ItemData() {}
    } data;

    void destroy() {
        switch (kind) {
        case ItemKind::Duck:
            data.duck.~DuckInstance();
            break;
        case ItemKind::Encounter:
            data.encounter.~EncounterInstance();
            break;
        }
    }
};
} // namespace nork

#endif // !NORK_ITEM_H
