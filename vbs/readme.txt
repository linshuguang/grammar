左值在我看来是与引用同义的东西，而引用的提出是在右值中明确以保留具体数据类型的方式来处理ADT
按值表明是不区分具体的变量类型的，其最根本的目的在于保留最基本的数据类型
而按引用则需要保留原始的变量类型，这几乎天生就是左值所要表明的意思
作为左值出现的变量应该具有variable的属性，variable具有别人不具有的赋值（assign）功能