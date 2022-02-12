# Allocate Helper

> Note: not stable
>
> Don't use before the stable release.
>
> plan to integrate with callable/allocator/… etc

Allocate helper to reduce too verbose code.

> Note: smart pointer in C++ is much better, Absolutely never needed it in production

## Usage

Without any helper (like smart pointers), code to allocate something will like …

```c
t_something *allocate_something(t_something_option *arg)
{
    t_something *result;

    result = malloc(sizeof(t_something));
    if (!result)
        return (NULL);
    result->some = something_alloc_some(result, arg);
    if (!result)
    {
        free(result);
        return (NULL);
    }
    result->more = something_alloc_more(result, arg);
    if (!result)
    {
        something_free_some(result->some);
        free(result);
        return (NULL);
    }
    result->fields = something_alloc_fields(result, arg);
    if (!result)
    {
        something_free_some(result->some);
        something_free_more(result->more);
        free(result);
        return (NULL);
    }
    result->might = something_alloc_might(result, arg);
    if (!result)
    {
        something_free_some(result->some);
        something_free_more(result->more);
        something_free_fields(result->fields);
        free(result);
        return (NULL);
    }
    result->exists = something_alloc_exists(result, arg);
    if (!result)
    {
        something_free_some(result->some);
        something_free_more(result->more);
        something_free_fields(result->fields);
        something_free_exists(result->exists);
        free(result);
        return (NULL);
    }
    return (result);
}
```

… which can expressed like below with this library

```c
t_something *allocate_something(t_something_option *arg)
{
    t_allocate_helper    *helper;
    t_something         *result;

    helper = new_allocate_helper(6);
    if (!helper)
        return (NULL);
    if (
        allocate_helper(helper, &result, malloc(sizeof(t_something)), free)
        || allocate_helper(helper, &result->some,
            something_alloc_some(arg), something_free_some)
        || allocate_helper(helper, &result->more,
            something_alloc_more(arg), something_free_more)
        || allocate_helper(helper, &result->fields,
            something_alloc_fields(arg), something_free_fields)
        || allocate_helper(helper, &result->might,
            something_alloc_might(arg), something_free_might)
        || allocate_helper(helper, &result->exists,
            something_alloc_exists(arg), something_free_exists)
    )
        result = NULL;
    free(helper);
    return (result);
}
```

… or you can allocate allocate_helper to stack

```c
t_something *allocate_something(t_something_option *arg)
{
    t_allocate_helper_item  items[6];
    t_allocate_helper       helper;
    t_something             *result;

    helper = allocate_helper_init(&helper, items, 6);
    if (
        allocate_helper(&helper, &result, malloc(sizeof(t_something)), free)
        || allocate_helper(&helper, &result->some,
            something_alloc_some(arg), something_free_some)
        || allocate_helper(&helper, &result->more,
            something_alloc_more(arg), something_free_more)
        || allocate_helper(&helper, &result->fields,
            something_alloc_fields(arg), something_free_fields)
        || allocate_helper(&helper, &result->might,
            something_alloc_might(arg), something_free_might)
        || allocate_helper(&helper, &result->exists,
            something_alloc_exists(arg), something_free_exists)
    )
        return (NULL);
    return (result);
}
```

To use it, you need to include its header.

```c
#include <ft/allocate_helper.h>
```

Include \*_\_types_.h instead if you don't want included size get too bigger and only need types not function prototypes (in header files for example)

```c
#include <ft/allocate_helper_types.h>
```

## Contributing

Any PR is welcome if below is kept

- _**[DON'T COMMIT FILES WITH 42 HEADER NOT REMOVED](#remove-42-header)**_
- If possible, keep the [Norm](https://github.com/42School/norminette)

### pre-commit hook

Run `init.sh` to initialize git pre-commit hook.

```sh
sh init.sh
```

It will copy `hooks/pre-commit.sh` into `.git/hooks/pre-commit`, and set execute permission on it.

#### remove 42 header

File history is handled really great by git.

Just let VCS handle it, and stop polluting history :)

This pre-commit script will remove 42 header from `Makefile` and `*.{c,h,sh,mk}` files

Alternative: run shell command below **before every commit**, or never touch 42 header

```sh
find . -name '*.c' -o -name "*.h" -o -name "*.sh" -o -name "*.mk" -o -name "Makefile" \
| xargs -L1 sh hooks/scripts/42header-remover.sh
```
