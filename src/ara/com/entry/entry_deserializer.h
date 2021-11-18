#ifndef ENTRY_DESERIALIZER_H
#define ENTRY_DESERIALIZER_H

#include "./eventgroup_entry.h"
#include "./service_entry.h"

namespace ara
{
    namespace com
    {
        namespace entry
        {
            /// @brief A helper class for deserialzing an entry payload
            class EntryDeserializer
            {
            public:
                /// @brief Deserialize an entry payload
                /// @param payload Serialized entry payload byte array
                /// @param offset Deserializing offset in the payload
                /// @returns Shared pointer to the entry which is created while deserializing
                /// @throws std::out_of_range Throws when the entry type for deserializing is not supported
                static std::shared_ptr<Entry> Deserialize(
                    const std::vector<uint8_t> &payload,
                    std::size_t &offset);
            };
        }
    }
}

#endif