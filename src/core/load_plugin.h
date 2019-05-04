#pragma once
#include <string>
#include <vector>
class Plugin;

Plugin* load_plugin(const std::string& path);
void unload_plugin(Plugin* plugin);

std::vector<Plugin*> load_all_plugins(const std::string& dir_path);
void unload_all_plugins(std::vector<Plugin*> plugins);
