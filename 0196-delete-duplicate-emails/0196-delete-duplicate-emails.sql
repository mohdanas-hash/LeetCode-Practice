delete from Person
where id in (
  select id
  from (
    select p2.id
    from Person p1, Person p2
    where p1.email = p2.email
    and p1.id < p2.id
  ) as duplicates
);