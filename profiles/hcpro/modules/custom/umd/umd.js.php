<!-- UMD -->
<script>
    var UMDS = <?php echo json_encode(variable_get('umd_site')); ?>; var UMD = [];    
<?php foreach($commands as $command): ?>
    UMD.push(<?php echo json_encode($command); ?>);
<?php endforeach; ?>   	
    (function() {
        var e = document.createElement('script'); e.type = 'text/javascript'; e.async = true;
        e.src = "<?= variable_get('umd_host') ?>/umd.js";
        var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(e, s);
    })();
</script>
