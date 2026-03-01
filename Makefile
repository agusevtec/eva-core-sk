.PHONY: build test shell clean

IMAGE_NAME = eva-core-test
CONTAINER_NAME = eva-test-runner

build:
	docker-compose build

test: build
	docker-compose up --abort-on-container-exit

shell:
	docker run -it --rm \
		-v $(PWD)/src:/test/src \
		-v $(PWD)/test:/test/test \
		-p 8080:8080 \
		--device=/dev:/dev \
		$(IMAGE_NAME) /bin/bash

clean:
	docker-compose down -v
	docker rmi $(IMAGE_NAME) || true

test-tickable:
	docker-compose run --rm arduino-tests python3 -c "from run_tests import *; VirtualAvrTester().run_single_test('test_tickable')"

test-button:
	docker-compose run --rm arduino-tests python3 -c "from run_tests import *; VirtualAvrTester().run_single_test('test_button')"

test-timers:
	docker-compose run --rm arduino-tests python3 -c "from run_tests import *; VirtualAvrTester().run_single_test('test_timers')"

rebuild: clean build test