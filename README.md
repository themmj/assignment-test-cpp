# assignment grading automation

Automatically run tests on a set of submissions for a programming assignment. Assignments should be based on [assignment-template-cpp](https://github.com/themmj/assignment-template-cpp).

## Prerequisites

- assignment:
   - is a C++ project
   - with a `src/` folder containing all the code
   - with a `main.cpp` containing the `main` function  
- each submission is a zip file containing the assignments whole repository (including `.git` folder)

## Features

Besides general build automation and some cmake fun, this project provides the following features:

### GTest capabilities

The individual testcases for an assignment are defined using [GTest](https://github.com/google/googletest). This means that all capabilities from assertions to mocking are possible.

### Execute the submission's `main`

The headers and cmake are configured in a way which renames the `main` function inside the submission's `main.cpp` when running the tests. This way it can be called with `CALL_ASSIGNMENT_MAIN` inside a test case, passing a variable number of arguments.

### Git user extraction

Extracts git user name from the latest commit to combat blatant copy/pasting of submissions.

### Score calculation

The score for a submission is calculated using the inverse of the ratio of failed tests vs. total tests.
A build error counts as 0%. In case a submission does not achieve 100% its test failures or build errors are preserved for manual investigation if needed.

### CSV export

The results are written to stdout and a result file in a CSV format using tabs as delimiters. (commas are not well suited as an error log may contain commas)

## Configuration

The assignment configuration resides in `./assignment.conf`. The individual parameters stand for the following:

- `submission_zips_location` (string) absolute or relative path to all the submissions
- `assignment_source_files` (array of strings) list of source files contained in each assignment (relative to the root of the submission repository)

## CLI options

- `-su` skip unzip. For the general use case: run the script once without this option and then always with this option. This allows you to edit the submissions code and rerun the tests without overwriting these edits with the zip content.
- `--submission=NR` run a single submission. Replace NR with the submission folder's number you want to run. E.g. `--submission=0` to run the first submission.
