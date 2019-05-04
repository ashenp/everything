# batchdo:

batchdo is a tiny collceter for executing commands across mutible servers,  use yaml config defaultly.

It is easily to develop for some other demond, mostly the naming services. you can develop for your own rules to find servers by register a new observer.



## Installtion

gcc 4.7 or later will be needed.

yaml-cpp will be needed. https://github.com/jbeder/yaml-cpp

then make.

## Using

only support long options;

--group(required) 

The group name to indicate the servers

--type(required)

The way to find servers 

--cmd(required)

The command to be executed

\--config (optional)

A config file required for some ways (like yaml, the default way).

## example

./batchdo  --type yaml --group test_group --cmd 'ps -ef | grep nginx' --config='/etc/batchdo/groups.yaml'


