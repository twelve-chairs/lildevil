#!/usr/bin/env bash

conan remove --locks
conan remove --src --system-reqs --builds -p --force '*'
