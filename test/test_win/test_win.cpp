// test_win.cpp : Defines the entry point for the console application.
//
#include "..\..\src\uuid.h"
#include <assert.h>
#include <iostream>

int main()
{
   using namespace uuids;

   {
      uuid empty;
      assert(empty.is_nil());
      assert(empty.size() == 16);
   }

   {
      uuid const guid = uuids::make_uuid();
      assert(!guid.is_nil());
      assert(guid.size() == 16);
      assert(guid.version() == uuids::version_type::random_number_based);
      assert(guid.variant() == uuids::variant_type::rfc);
   }

   {
      uuid empty;
      uuid guid = uuids::make_uuid();

      assert(empty == empty);
      assert(guid == guid);
      assert(empty != guid);
   }

   {
      uuid empty;
      uuid guid = uuids::make_uuid();

      assert(empty.is_nil());
      assert(!guid.is_nil());

      std::swap(empty, guid);

      assert(!empty.is_nil());
      assert(guid.is_nil());

      empty.swap(guid);

      assert(empty.is_nil());
      assert(!guid.is_nil());
   }

   {
      uuid empty;
      assert(empty.string() == "00000000-0000-0000-0000-000000000000");
      assert(empty.wstring() == L"00000000-0000-0000-0000-000000000000");
   }

   {
      using namespace std::string_literals;

      auto str = "47183823-2574-4bfd-b411-99ed177d3e43"s;
      uuid guid(str);
      assert(guid.string() == str);
   }

   {
      using namespace std::string_literals;

      auto str = L"47183823-2574-4bfd-b411-99ed177d3e43"s;
      uuid guid(str);
      assert(guid.wstring() == str);
   }

   {
      constexpr uuid empty;
      constexpr bool isnil = empty.is_nil();
      constexpr size_t size = empty.size();
      constexpr uuids::variant_type variant = empty.variant();
      constexpr uuids::version_type version = empty.version();
   }

   return 0;
}

