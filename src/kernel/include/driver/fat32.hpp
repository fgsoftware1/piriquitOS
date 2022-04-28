#ifndef FAT32_H
#define FAT32_H

#include "../disks.hpp"
#include "stl/vector.hpp"
#include "stl/string.hpp"

namespace fat32
{
  typedef const disks::disk_descriptor &dd;

  uint64_t free_size(dd disk, const disks::partition_descriptor &partition);
  std::vector<disks::file> ls(dd disk, const disks::partition_descriptor &partition, const std::vector<std::string> &path);
  std::string read_file(dd disk, const disks::partition_descriptor &partition, const std::vector<std::string> &path, const std::string &file);
  bool mkdir(dd disk, const disks::partition_descriptor &partition, const std::vector<std::string> &path, const std::string &directory);
  bool touch(dd disk, const disks::partition_descriptor &partition, const std::vector<std::string> &path, const std::string &file);
  bool rm(dd disk, const disks::partition_descriptor &partition, const std::vector<std::string> &path, const std::string &file);
}
#endif
