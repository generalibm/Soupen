#ifndef YEDIS_DB_H_#define YEDIS_DB_H_#include "../ds/yedis_bloom_filter.h"#include "../ds/yedis_trie.h"#include "../ds/yedis_string.h"#define MAX_DB 16namespace yedis_server{  using yedis_datastructures::YedisNormalString;  using yedis_datastructures::YedisBloomFilter;  using yedis_datastructures::YedisTrie;  using yedis_datastructures::YedisTrieNode;  template<typename T>  struct YedisDSTypeNode  {    ~YedisDSTypeNode()    {      val->~T();      key->~YedisNormalString();    }    T *val;    YedisDSTypeNode *next;    YedisNormalString *key;  };  struct YedisDBElement  {    YedisDBElement()    {      bf = nullptr;      tn = nullptr;    }    YedisDSTypeNode<YedisBloomFilter> *bf;    YedisDSTypeNode<YedisTrie<YedisTrieNode> > *tn;  };  extern YedisDBElement ydbe[MAX_DB];}#endif /*YEDIS_DB_H_*/