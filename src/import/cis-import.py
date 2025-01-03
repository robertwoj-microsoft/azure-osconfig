from dataclasses import asdict

import yaml
from model import CISBenchmark
import sys
from typing import List
from excel import parse_CIS_Excel
from mof import dump_mof

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: python {sys.argv[0]} <input_directory> <output_file>")
        sys.exit(1)

    input_directory = sys.argv[1]
    output_file = sys.argv[2]
    model = parse_CIS_Excel(input_directory)
    with open(output_file, 'w') as f:
        yaml.dump(asdict(model), f)

    dump_mof(model.benchmarks, "cis.mof")
